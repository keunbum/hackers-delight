#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int n) {
  const int md = (int) 1e9 + 7;
  auto Add = [&](int& a, int b) {
    a += b;
    if (a >= md) a -= md;
  };
  const int N = (int) 6e4;
  vector<int> dp(N + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    Add(dp[i], dp[i - 2]);
    Add(dp[i], dp[i - 1]);
  }
  return dp[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << solution(1) << endl;
  cout << solution(2) << endl;
  cout << solution(3) << endl;
  cout << solution(4) << endl;
  cout << solution(5) << endl;
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * keep calm
  
 * stuff you should look for
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