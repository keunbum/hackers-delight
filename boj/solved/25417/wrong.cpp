#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<int>> a(7, vector<int>(7, -1));
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> a[i][j];
    }
  }
  int r, c;
  cin >> r >> c;
  ++r; ++c;
  vector<pair<int, int>> que(1, {r, c});
  vector<vector<int>> dist(7, vector<int>(7, -1));
  dist[r][c] = 0;
  for (int b = 0; b < (int) que.size(); b++) {
    auto[mi, mj] = que[b];
    if (a[mi][mj] == 1) {
      cout << dist[mi][mj] << '\n';
      return 0;
    }
    for (auto[di, dj] : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
      int ni = mi + di;
      int nj = mj + dj;
      if (a[ni][nj] == -1 || dist[ni][nj] != -1) {
        continue;
      }
      dist[ni][nj] = dist[mi][mj] + 1;
      que.emplace_back(ni, nj);
      while (a[ni + di][nj + dj] != -1 && a[ni][nj] != 7) {
        ni += di;
        nj += dj;
      }
      if (dist[ni][nj] == -1) {
        dist[ni][nj] = dist[mi][mj] + 1;
        que.emplace_back(ni, nj);
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}