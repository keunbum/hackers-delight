#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int K = 9;
  int n;
  cin >> n;
  vector<array<bool, K>> dp(n + 1);
  for (int i = 0; i < K; ++i) {
    dp[0][i] = true;
  }
  for (int i = 1; i <= n; ++i) {
    int m;
    cin >> m;
    while (m--) {
      int a;
      cin >> a;
      --a;
      for (int j = 0; j < K; ++j) {
        if (j != a) {
          dp[i][a] |= dp[i - 1][j];
        }
      }
    }
  }
  vector<int> res;
  int pre = -1;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < K; ++j) {
      if (j != pre && dp[i][j]) {
        debug(i, j, pre);
        pre = j;
        res.push_back(j);
        break;
      }
    }
  }
  if ((int) res.size() != n) {
    cout << -1 << '\n';
    return 0;
  }
  reverse(res.begin(), res.end());
  for (int x : res) {
    cout << x + 1 << '\n';
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  
 * stuff you should look for
  * 0-based or 1-based?
  * off-by-one error
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/