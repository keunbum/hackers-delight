#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

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
    debug(mi, mj);
    if (a[mi][mj] == 1) {
      cout << dist[mi][mj] << '\n';
      return 0;
    }
    for (auto[di, dj] : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
      int ni = mi + di;
      int nj = mj + dj;
      if (a[ni][nj] == -1) {
        continue;
      }
      if (dist[ni][nj] == -1) {
        dist[ni][nj] = dist[mi][mj] + 1;
        que.emplace_back(ni, nj);
        debug(ni, nj);
      }
      while (a[ni + di][nj + dj] != -1 && a[ni][nj] != 7) {
        ni += di;
        nj += dj;
      }
      if (dist[ni][nj] == -1) {
        dist[ni][nj] = dist[mi][mj] + 1;
        que.emplace_back(ni, nj);
        debug(ni, nj);
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/