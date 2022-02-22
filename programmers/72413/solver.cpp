#include <bits/stdc++.h>

using namespace std;

int solution(int n, int S, int A, int B, vector<vector<int>> edges) {
  --S; --A; --B;
  const int inf = (int) 1e9;
  vector<vector<int>> dp(n, vector<int>(n, inf));
  for (vector<int>& e : edges) {
    --e[0]; --e[1];
    dp[e[0]][e[1]] = dp[e[1]][e[0]] = e[2];
  }
  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (dp[i][k] == inf) {
        continue;
      }
      for (int j = 0; j < n; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  int ans = inf;
  int K;
  for (K = 0; K < n; K++) {
    if (dp[S][K] == inf || dp[K][A] == inf || dp[K][B] == inf) continue;
    ans = min(ans, dp[S][K] + dp[K][A] + dp[K][B]);
  }
  return ans;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
  * 0-based or 1-based?
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/