#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<int> dp(w, 0);
  for (int i = 0; i < h; i++) {
    vector<int> new_dp(w);
    for (int j = 0; j < w; j++) {
      int mx = 0;
      if (j > 0) mx = new_dp[j - 1];
      if (i > 0) mx = max(mx, dp[j]);
      cin >> new_dp[j];
      new_dp[j] += mx;
    }
    swap(dp, new_dp);
  }
  cout << dp[w - 1] << '\n';
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