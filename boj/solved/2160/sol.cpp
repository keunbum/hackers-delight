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
  int ans = 36;
  int n;
  cin >> n;
  assert(n >= 2);
  vector<vector<string>> a(n, vector<string>(5));
  for (int i = 0; i < n; ++i) {
    for (int x = 0; x < 5; ++x) {
      cin >> a[i][x];
    }
  }
  int v = -1, u = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int cnt = 0;
      for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 7; ++y) {
          cnt += a[i][x][y] != a[j][x][y];
        }
      }
      if (cnt < ans) {
        v = i;
        u = j;
        ans = cnt;
      }
    }
  }
  cout << v + 1 << " " << u + 1 << '\n';
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