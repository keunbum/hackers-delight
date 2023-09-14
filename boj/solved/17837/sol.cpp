#include <bits/stdc++.h>

using namespace std;

const int DX[4] = {0, 0, -1, 1};
const int DY[4] = {1, -1, 0, 0};

struct Room {
  int sz;
  int top;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  vector<vector<Room>> rs(n, vector<Room>(n, {0, -1}));
  vector<array<int, 3>> ps(k);
  for (int i = 0; i < k; ++i) {
    int x, y, dir;
    cin >> x >> y >> dir;
    --x; --y; --dir;
    ps[i] = {x, y, dir};
    rs[x][y] = {1, i};
  }
  vector<int> nxt(k, -1);
  vector<int> pre(k, -1);
  for (int turn = 1; turn <= 1000; ++turn) {
    for (int i = 0; i < k; ++i) {
      int x = ps[i][0];
      int y = ps[i][1];
      int& dir = ps[i][2];
      for (int rep = 0; rep < 2; ++rep) {
        int nx = x + DX[dir];
        int ny = y + DY[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[nx][ny] == 2) {
          if (rep == 0) {
            dir ^= 1;
          }
          continue;
        }
        int v = i;
        if (pre[v] != -1) {
          nxt[pre[v]] = -1;
        }
        rs[x][y].top = pre[v];
        vector<int> us;
        while (v != -1) {
          us.push_back(v);
          v = nxt[v];
        }
        if (a[nx][ny] == 1) {
          reverse(us.begin(), us.end());
        }
        for (int u : us) {
          if (rs[nx][ny].top != -1) {
            nxt[rs[nx][ny].top] = u;
          }
          pre[u] = rs[nx][ny].top;
          nxt[u] = -1;
          rs[nx][ny].top = u;
          rs[nx][ny].sz += 1;
          rs[x][y].sz -= 1;
          ps[u][0] = nx;
          ps[u][1] = ny;
        }
        if (rs[nx][ny].sz >= 4) {
          cout << turn << '\n';
          return 0;
        }
        break;
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}
