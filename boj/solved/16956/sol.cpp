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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; ++i) {
    cin >> s[i];
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '.') {
        s[i][j] = 'D';
      }
    }
  }
  const int di[] = {1, 0, -1, 0};
  const int dj[] = {0, 1, 0, -1};
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == 'S') {
        for (int dir = 0; dir < 4; ++dir) {
          int ni = i + di[dir];
          int nj = j + dj[dir];
          if (ni >= 0 && nj >= 0 && ni < h && nj < w && s[ni][nj] == 'W') {
            cout << 0 << '\n';
            return 0;
          }
        }
      }
    }
  }
  cout << 1 << '\n';
  for (int i = 0; i < h; ++i) {
    cout << s[i] << '\n';
  }
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