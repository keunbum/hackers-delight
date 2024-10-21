#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int solution(string s) {
  int n = (int) s.size();
  vector<vector<bool>> dp(n, vector<bool>(n, false));
  int ret = 1;
  for (int i = 0; i < n; ++i) {
    dp[i][i] = true;
    if (i + 1 < n) {
      dp[i][i + 1] = s[i] == s[i + 1];
      if (dp[i][i + 1]) {
        ret = 2;
      }
    }
  }
  for (int L = 3; L <= n; ++L) {
    for (int i = 0; i + L <= n; ++i) {
      int j = i + L - 1;
      dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
      if (dp[i][j]) {
        ret = L;
      }
    }
  }
  debug(ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution("abcdcba"	);
  solution("abacde"	);
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