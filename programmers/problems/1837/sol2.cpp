#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int solution(int n, int, vector<vector<int>> edges, int k, vector<int> gps_log) {
  for (auto& v : gps_log) {
    --v;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n; ++i) {
    g[i].push_back(i);
  }
  for (auto& edge : edges) {
    int x = edge[0] - 1;
    int y = edge[1] - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  const int inf = (int) 1e8;
  vector<int> dp(n, inf);
  dp[gps_log[0]] = 0;
  for (int t = 1; t < k; ++t) {
    vector<int> ndp(n, inf);
    for (int v = 0; v < n; ++v) {
      for (int u : g[v]) {
        ndp[v] = min(ndp[v], dp[u] + (v != gps_log[t]));
      }
    }
    swap(dp, ndp);
  }
  return dp[gps_log[k - 1]] == inf ? -1 : dp[gps_log[k - 1]];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution( 7, 10, {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}}, 6, {1, 2, 3, 3, 6, 7});
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