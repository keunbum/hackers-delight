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
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<vector<bool>> p(n, vector<bool>(n, false));
  for (int i = 0; i < n; ++i) {
    p[i][i] = true;
  }
  for (int L = 2; L <= n; ++L) {
    for (int i = 0; i + L <= n; ++i) {
      int j = i + L - 1;
      p[i][j] = (s[i] == s[j] && (L == 2 || p[i + 1][j - 1]));
    }
  }
  vector<int> dp(n + 1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = i + 1;
    for (int j = 0; j <= i; ++j) {
      if (!p[j][i]) {
        continue;
      }
      dp[i + 1] = min(dp[i + 1], dp[j] + 1);
    }
  }
  cout << dp[n] << '\n';
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