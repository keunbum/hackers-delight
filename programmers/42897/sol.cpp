﻿#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<int> money) {
  int n = (int) money.size();
  int ret = 0;
  for (int t = 0; t < 2; t++) {
    vector<array<int, 2>> dp(n);
    dp[0][0] = 0;
    dp[0][1] = (t == 0 ? 0 : money[0]);
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = (t == 0 || i < n - 1) ? dp[i - 1][0] + money[i] : 0;
    }
    ret = max({ret, dp[n - 1][0], dp[n - 1][1]});
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
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
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/