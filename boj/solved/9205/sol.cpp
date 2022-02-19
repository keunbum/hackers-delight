#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    n += 2;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = dp[j][i] = (abs(x[j] - x[i]) + abs(y[j] - y[i]) <= 1000);
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        if (dp[i][k] == 0) continue;
        for (int j = 0; j < n; j++) {
          dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]);
        }
      }
    }     
    cout << (dp[0][n - 1] ? "happy" : "sad") << '\n';
  }
  return 0;
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