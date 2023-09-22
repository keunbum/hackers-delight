#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  auto In = [&](int i, int j) { return min(i, j) >= 0 && max(i, j) < n; };
  vector<vector<array<int, 2>>> a(n, vector<array<int, 2>>(n));
  vector<array<int, 3>> info(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      --x;
      if (x == -1) {
        a[i][j][1] = -k;
      } else {
        a[i][j] = {x, 0};
        info[x][0] = i;
        info[x][1] = j;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    cin >> info[i][2];
    --info[i][2];
  }
  vector<array<array<int, 4>, 4>> dirs(m);
  for (int i = 0; i < m; ++i) {
    for (int dir = 0; dir < 4; ++dir) {
      for (int j = 0; j < 4; ++j) {
        cin >> dirs[i][dir][j];
        --dirs[i][dir][j];
      }
    }
  }
  for (int turn = 0; turn < 1000; ++turn) {
    for (int i = 0; i < m; ++i) {
      auto[mi, mj, mdir] = info[i];
      if (mi == -1) {
        continue;
      }
      const int di[] = {-1, 1, 0, 0};
      const int dj[] = {0, 0, -1, 1};
      bool found = false;
      for (int dir : dirs[i][mdir]) {
        int ni = mi + di[dir];
        int nj = mj + dj[dir];
        if (In(ni, nj) && turn - a[ni][nj][1] >= k) {
          found = true;
          info[i] = {ni, nj, dir};
          break;
        }
      }
      if (found) {
        continue;
      }
      for (int dir : dirs[i][mdir]) {
        int ni = mi + di[dir];
        int nj = mj + dj[dir];
        if (In(ni, nj) && turn - a[ni][nj][1] < k && a[ni][nj][0] == i) {
          info[i] = {ni, nj, dir};
          break;
        }
      }
    }
    set<pair<int, int>> s;
    for (int i = 0; i < m; ++i) {
      auto[mi, mj, _] = info[i];
      if (mi == -1) {
        continue;
      }
      if (!s.emplace(mi, mj).second) {
        info[i][0] = -1;
        continue;
      }
      a[mi][mj] = {i, turn + 1};
    }
    if ((int) s.size() == 1) {
      cout << turn + 1 << '\n';
      return 0;
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
  
 * stuff you should look for
  * 0-based or 1-based?
  * off-by-one error
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/