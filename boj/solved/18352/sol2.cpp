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
  int n, m, k, st;
  cin >> n >> m >> k >> st;
  --st;
  vector<vector<int>> g(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
  }
  vector<int> dist(n, -1);
  dist[st] = 0;
  vector<int> que(1, st);
  vector<int> ret;
  for (int b = 0; b < (int) que.size(); b++) {
    int v = que[b];
    if (dist[v] == k) {
      ret.push_back(v);
    }
    for (int u : g[v]) {
      if (dist[u] == -1) {
        dist[u] = dist[v] + 1;
        que.push_back(u);
      }
    }
  }
  if (ret.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  sort(ret.begin(), ret.end());
  for (int i = 0; i < (int) ret.size(); i++) {
    cout << ret[i] + 1 << '\n';
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