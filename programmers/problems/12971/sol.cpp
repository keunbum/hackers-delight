#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<int> a) {
  int ret = 0;
  int n = (int) a.size();
  if (n == 1) {
    return a[0];
  }
  vector<array<int, 2>> dp(n);
  {
    vector<array<int, 2>> dp(n);
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
      dp[i][1] = dp[i - 1][0] + a[i];
    }
    debug(dp);
    ret = dp[n - 1][0];
  }
  {
    vector<array<int, 2>> dp(n);
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
      dp[i][1] = dp[i - 1][0] + a[i];
    }
    debug(dp);
    ret = max({ret, dp[n - 1][0], dp[n - 1][1]});      
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({14, 6, 5, 11, 3, 9, 2, 10});
  solution({1, 3, 2, 5, 4});
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
 * stuff you should look for
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