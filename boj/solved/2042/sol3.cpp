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
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> dist(n, -1);
  vector<int> parent(n, -1);
  {
    vector<int> que(1, 0);
    dist[0] = 0;
    parent[0] = 0;
    for (int b = 0; b < (int) que.size(); b++) {
      int v = que[b];
      for (int u : g[v]) {
        if (dist[u] == -1) {
          dist[u] = dist[v] + 1;
          parent[u] = v;
          que.push_back(u);
        }
      }
    }
  }
  const int LOG = 18;
  vector<array<int, LOG>> nxt(n);
  for (int i = 0; i < n; i++) {
    nxt[i][0] = parent[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i < n; i++) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    }
  }
  auto LCA = [&](int u, int v) {
    if (dist[u] < dist[v]) {
      swap(u, v);
    }
    for (int j = LOG - 1; j >= 0; j--) {
      if (dist[u] - (1 << j) >= dist[v]) {
        u = nxt[u][j];
      }
    }
    if (u == v) {
      return u;
    }
    for (int j = LOG - 1; j >= 0; j--) {
      if (nxt[u][j] != nxt[v][j]) {
        u = nxt[u][j];
        v = nxt[v][j];
      }
    }
    return parent[u];
  };
  int m;
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    cout << LCA(x, y) + 1 << '\n';
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