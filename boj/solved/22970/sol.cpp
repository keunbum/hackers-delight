#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> L(n);
  L[0] = 1;
  for (int i = 1; i < n; ++i) {
    L[i] = a[i - 1] < a[i] ? L[i - 1] + 1 : 1;
  }
  vector<int> R(n);
  R[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    R[i] = a[i] > a[i + 1] ? R[i + 1] + 1 : 1;
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, L[i] + R[i] - 1);
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