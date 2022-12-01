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
  vector<vector<bool>> wall(h, vector<bool>(w, false));
  for (int j = 0; j < w; j++) {
    int b;
    cin >> b;
    for (int i = h - 1; i >= h - b; i--) {
      wall[i][j] = true;
    }
  }
  vector<vector<int>> lft(h, vector<int>(w));
  vector<vector<int>> rgt(h, vector<int>(w));
  int ret = 0;
  for (int i = 0; i < h; i++) {
    lft[i][0] = (wall[i][0] ? 0 : -1);
    for (int j = 1; j < w; j++) {
      lft[i][j] = (wall[i][j] ? j : lft[i][j - 1]);
    }
    rgt[i][w - 1] = (wall[i][w - 1] ? w - 1 : -1);
    for (int j = w - 2; j >= 0; j--) {
      rgt[i][j] = (wall[i][j] ? j : rgt[i][j + 1]);
    }
    for (int j = 0; j < w; j++) {
      ret += (!wall[i][j] && lft[i][j] != -1 && rgt[i][j] != -1);
    }
  }
  cout << ret << '\n';
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