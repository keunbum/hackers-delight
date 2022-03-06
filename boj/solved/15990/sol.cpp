#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 9;

int add(int x, int y) {
  x += y;
  if (x >= md) x -= md;
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 100000;
  vector<vector<int>> dp(N + 1, vector<int>(3, 0));
  dp[1][0] = 1;
  dp[2][1] = 1;
  dp[3][0] = 1;
  dp[3][1] = 1;
  dp[3][2] = 1;
  for (int i = 4; i <= N; i++) {
    dp[i][0] = add(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = add(dp[i - 2][0], dp[i - 2][2]);
    dp[i][2] = add(dp[i - 3][0], dp[i - 3][1]);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << add(add(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
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