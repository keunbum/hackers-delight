#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int di[] = {1, 0, -1, 0};
  const int dj[] = {0, 1, 0, -1};
  int w, h;
  cin >> w >> h;
  vector<string> s(h);
  for (int i = 0; i < h; ++i) {
    cin >> s[i];
  }
  array<int, 2> ret{};
  vector<vector<bool>> was(h, vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!was[i][j]) {
        was[i][j] = true;
        function<int(int, int)> DFS = [&](int mi, int mj) {
          int ret = 1;
          for (int dir = 0; dir < 4; ++dir) {
            int ni = mi + di[dir];
            int nj = mj + dj[dir];
            if (ni >= 0 && nj >= 0 && ni < h && nj < w && s[ni][nj] == s[i][j] && !was[ni][nj]) {
              was[ni][nj] = true;
              ret += DFS(ni, nj);
            }
          }
          return ret;
        };
        int sz = DFS(i, j);
        ret[s[i][j] == 'B'] += sz * sz;
      }
    }
  }
  cout << ret[0] << " " << ret[1] << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * Do I have to solve like this?
  
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
