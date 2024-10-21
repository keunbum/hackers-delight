#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(string st, string en, vector<string> words) {
  words.push_back(st);
  int n = (int) words.size();
  int p = -1;
  for (int i = 0; i < n; i++) {
    if (words[i] == en) {
      p = i;
    }
  }
  if (p == -1) {
    return 0;
  }
  const int inf = (int) 1e8;
  vector<vector<int>> dp(n, vector<int>(n, inf));
  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int cnt = 0;
      for (int ii = 0; ii < (int) words[i].size(); ii++) {
        cnt += (words[i][ii] != words[j][ii]);
      }
      if (cnt == 1) {
        dp[i][j] = dp[j][i] = 1;
      }
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  return dp[n - 1][p];
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