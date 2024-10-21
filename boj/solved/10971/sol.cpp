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
  const int inf = int(1e9);
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      if (i != j && a[i][j] == 0) {
        a[i][j] = inf;
      }
    }
  }
  int64_t ans = int64_t(1e18);
  vector<int> perm(n - 1);
  iota(perm.begin(), perm.end(), 0);
  do {
    int64_t v = a[n - 1][perm[0]];
    for (int id = 0; id < n - 1; ++id) {
      int i = perm[id];
      int j = id == n - 2 ? n - 1 : perm[id + 1];
      v += a[i][j];
    }
    ans = min(ans, v);
  } while (next_permutation(perm.begin(), perm.end()));
  cout << ans << '\n';
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
