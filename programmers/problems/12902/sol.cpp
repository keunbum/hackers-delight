#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int md = (int) 1e9 + 7;

void add(int& a, int b) {
  a += b;
  if (a >= md) a -= md;
}
 
int mul(int a, int b) {
  return (long long) a * b % md;
}

int solution(int n) {
  array<int, 5001> dp;
  dp[0] = 1;
  dp[1] = 0;
  dp[2] = 3;
  dp[3] = 0;
  for (int i = 4; i <= n; i++) {
    dp[i] = mul(dp[i - 2], 3);
    for (int j = 4; j <= i; j += 2) {
      add(dp[i], mul(dp[i - j], 2));
    }
  }
  return dp[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << solution(n) << '\n';
  }
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