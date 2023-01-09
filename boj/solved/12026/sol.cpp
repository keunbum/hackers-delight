#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int idx[128];
  for (int i = 0; i < 3; i++) {
    idx[(int)"BOJ"[i]] = i;
  }
  int n;
  cin >> n;
  string s;
  cin >> s;
  const int inf = (int) 1e9;
  vector<int> dp(n, inf);
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {
    int p = (idx[(int)s[i]] + 1) % 3;
    for (int j = n - 1; j > i; j--) {
      if (idx[(int)s[j]] == p) {
        dp[i] = min(dp[i], (j - i) * (j - i) + dp[j]);
      }
    }
  }
  cout << (dp[0] == inf ? -1 : dp[0]) << '\n';
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