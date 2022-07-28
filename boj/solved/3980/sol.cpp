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
  const int n = 11;
  int tt;
  cin >> tt;
  while (tt--) {
    array<array<int, n>, n> rows;
    array<vector<int>, n> us;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> rows[i][j];
        if (rows[i][j] > 0) {
          us[i].push_back(j);
        }
      }
    }
    int mx = -1;
    vector<bool> used(n, false);
    function<void(int, int)> Dfs = [&](int v, int w) {
      if (v == n) {
        mx = max(mx, w);
        return;
      }
      for (int u : us[v]) {
        if (!used[u]) {
          used[u] = true;
          Dfs(v + 1, w + rows[v][u]);
          used[u] = false;
        }
      }
    };
    Dfs(0, 0);
    assert(mx != -1);
    cout << mx << '\n';
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