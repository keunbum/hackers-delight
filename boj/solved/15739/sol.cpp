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
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  vector<int> v(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      v[i * n + j] = a[i][j];
    }
  }
  sort(v.begin(), v.end());
  bool ok = true;
  ok &= adjacent_find(v.begin(), v.end()) == v.end();
  int s = n * (n * n + 1) / 2;
  for (int r = 0; r < 2; ++r) {
    for (int i = 0; i < n; ++i) {
      int c = 0;
      for (int j = 0; j < n; ++j) {
        c += (r == 0 ? a[i][j] : a[j][i]);
      }
      ok &= (c == s);
    }
  }
  {
    int c = 0;
    for (int i = 0; i < n; ++i) {
      c += a[i][i];
    }
    ok &= (c == s);
  } 
  {
    int c = 0;
    for (int i = 0; i < n; ++i) {
      c += a[i][n - 1 - i];
    }
    ok &= (c == s);
  } 
  cout << (ok ? "TRUE" : "FALSE") << '\n';
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