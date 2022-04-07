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
  int h, w;
  cin >> h >> w;
  vector<vector<int>> g(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int x, y, z;
      cin >> x >> y >> z;
      g[i][j] = x + y + z;
    }
  }
  int T;
  cin >> T;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      g[i][j] = (g[i][j] >= 3 * T);
    }
  }        
  for (int i = 0; i < h; i++) {
    debug(g[i]);
  }
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      debug(i, j, g[i][j]);
      if (!g[i][j]) {
        continue;
      }
      ++ans;
      g[i][j] = 0;
      vector<pair<int, int>> que(1, make_pair(i, j));
      for (int b = 0; b < (int) que.size(); b++) {
        auto[mi, mj] = que[b];
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            if (di * di + dj * dj != 1) {
              continue;
            }
            int ni = mi + di;
            int nj = mj + dj;
            if (ni >= 0 && nj >= 0 && ni < h && nj < w && g[ni][nj]) {
              g[ni][nj] = 0;
              que.emplace_back(ni, nj);
            }
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
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