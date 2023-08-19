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
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
  int q;
  cin >> q;
  while (q--) {
    int c;
    cin >> c;
    if (c & 1) {
      int i;
      cin >> i;
      --i;
      a[i].insert(a[i].begin(), a[i].back());
      a[i].erase(prev(a[i].end()));
    } else {
      vector<vector<int>> new_a(n, vector<int>(n));
      for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) new_a[j][n - 1 - i] = a[i][j];
      swap(a, new_a);
    }
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cout << a[i][j] << " \n"[j == n - 1];
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