#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cost(n);
  for (int i = 0; i < n; ++i) {
    cin >> cost[i];
  }
  vector<vector<bool>> g(n, vector<bool>(n, false));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      g[i][j] = (int) (s[j] - '0');
    }
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      if (!g[i][k]) {
        continue;
      }
      for (int j = 0; j < n; ++j) {
        g[i][j] = g[i][j] | (g[i][k] & g[k][j]);
      }
    }
  }
  vector<bool> was(n, false);
  int ans = 0;
  for (int v = 0; v < n; ++v) {
    if (was[v]) {
      continue;
    }
    int min_cost = cost[v];
    for (int u = 0; u < n; ++u) {
      if (g[v][u] && g[u][v]) {
        was[u] = true;
        min_cost = min(min_cost, cost[u]);
      }
    }
    ans += min_cost;
  }
  cout << ans << '\n';
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