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
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    g[x].emplace_back(y, z);
  }
  int st, en;
  cin >> st >> en;
  --st; --en;
  vector<int> dist(n, (int) 1e9);
  vector<int> p(n, -1);
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
    dist[st] = 0;
    s.emplace(dist[st], st);
    while (!s.empty()) {
      auto[expected, v] = s.top();
      s.pop();
      if (expected != dist[v]) {
        continue;
      }
      for (auto[u, w] : g[v]) {
        if (dist[u] > dist[v] + w) {
          dist[u] = dist[v] + w;
          p[u] = v;
          s.emplace(dist[u], u);
        }
      }
    }
  }
  vector<int> path(1, en);
  int v = en;
  do {
    v = p[v];
    path.push_back(v);
  } while (v != st);
  cout << dist[en] << '\n';
  int sz = (int) path.size();
  cout << sz << '\n';
  for (int i = sz - 1; i >= 0; i--) {
    cout << path[i] + 1 << " \n"[i == 0];
  }
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
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/