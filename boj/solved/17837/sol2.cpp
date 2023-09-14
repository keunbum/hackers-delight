#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
  vector<vector<vector<int>>> g(n, vector<vector<int>>(n));
  vector<array<int, 3>> ps(k);
  for (int i = 0; i < k; ++i) {
    int x, y, dir;
    cin >> x >> y >> dir;
    --x; --y; --dir;
    ps[i] = {x, y, dir};
    g[x][y].push_back(i);
  }
  for (int turn = 1; turn <= 1000; ++turn) {
    for (int i = 0; i < k; ++i) {
      int x = ps[i][0];
      int y = ps[i][1];
      int& dir = ps[i][2];
      for (int rep = 0; rep < 2; ++rep) {
        int nx = x + "1102"[dir] - '1';
        int ny = y + "2011"[dir] - '1';
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[nx][ny] == 2) {
          if (rep == 0) {
            dir ^= 1;
          }
          continue;
        }
        vector<int> us;
        while (true) {
          us.push_back(g[x][y].back());
          g[x][y].pop_back();
          if (us.back() == i) {
            break;
          }
        }
        if (a[nx][ny] == 0) {
          reverse(us.begin(), us.end());
        }
        for (int u : us) {
          g[nx][ny].push_back(u);
          ps[u][0] = nx;
          ps[u][1] = ny;
        }
        if ((int) g[nx][ny].size() >= 4) {
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
