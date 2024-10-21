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
  vector<char> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<array<int, 2>> dp(n);
  dp[0][0] = (a[0] == 'T');
  dp[0][1] = (a[0] == 'F');
  for (int i = 2; i < n; i += 2) {
    if (a[i] == 'F') {
      if (a[i - 1] == '&') {
        dp[i][0] = min(dp[i - 2][0], dp[i - 2][1]);
        dp[i][1] = min(dp[i - 2][1] + 1, dp[i - 2][0] + 2);
      }
      if (a[i - 1] == '|') {
        dp[i][0] = min(dp[i - 2][0], dp[i - 2][1] + 1);
        dp[i][1] = min(dp[i - 2][1], dp[i - 2][0] + 1);
      }
    }
    if (a[i] == 'T') {
      if (a[i - 1] == '&') {
        dp[i][0] = min(dp[i - 2][0], dp[i - 2][1] + 1);
        dp[i][1] = min(dp[i - 2][1], dp[i - 2][0] + 1);
      }
      if (a[i - 1] == '|') {
        dp[i][0] = min(dp[i - 2][0] + 1, dp[i - 2][1] + 2);
        dp[i][1] = min(dp[i - 2][0], dp[i - 2][1]);
      }
    }
  }
  char C;
  cin >> C;
  cout << dp[n - 1][C == 'T'] << '\n';
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
