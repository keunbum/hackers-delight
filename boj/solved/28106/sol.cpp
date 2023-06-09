#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

const int md = 998244353;

void Add(int& a, int b) {
  a += b;
  if (a >= md) a -= md;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  int root = -1;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    if (p != -1) {
      g[p].push_back(i);
    } else {
      root = i;
    }
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> dp(n);
  vector<int> depth(n);
  vector<int> stk;
  function<void(int)> DFS = [&](int v) {
    if (g[v].empty()) {
      dp[v] = 1;
      return;
    }
    stk.push_back(v);
    dp[v] = 0;
    for (int u : g[v]) {
      depth[u] = depth[v] + 1;
      DFS(u);
      for (int b = 0; b < (int) stk.size(); ++b) {
        if (depth[u] - depth[stk[b]] <= a[stk[b]]) {
          Add(dp[stk[b]], dp[u]);
        }
      }
    }
    stk.pop_back();
  };
  depth[root] = 0;
  DFS(root);
  cout << dp[root] << '\n';
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