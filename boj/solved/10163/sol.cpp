#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

const int M = 1001;
int a[M][M];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int it = 0; it < n; ++it) {
    int x, y, h, w;
    cin >> x >> y >> h >> w;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        a[x + i][y + j] = it + 1;
      }
    }
  }
  vector<int> ret(n + 1, 0);
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < M; ++j) {
      ret[a[i][j]] += 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ret[i] << '\n';
  }
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