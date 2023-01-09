﻿#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, A, B;
  cin >> N >> A >> B;
  int n = 8 - N;
  vector<int> X(n), Y(n);
  for (int i = 0; i < n; i++) {
    cin >> X[i] >> Y[i];
  }
  int a = max(66 - A, 0);
  int b = max(130 - B, 0);
  vector<vector<bool>> dp(a + 1, vector<bool>(b + 1, false));
  dp[0][0] = true;
  for (int step = n - 1; step >= 0; step--) {
    for (int i = a; i >= 0; i--) {
      for (int j = b; j >= 0; j--) {
        for (int x = 0; x <= X[step]; x++) {
          for (int y = 0; y <= Y[step]; y++) {
            if (x + y <= 6) {
              dp[i][j] = dp[i][j] | dp[max(i - 3 * x, 0)][max(j - 3 * (x + y), 0)];
            }
          }
        }
      }
    }
  }
  cout << (dp[a][b] ? "Nice" : "Nae ga wae") << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/