#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

class dsu {
public:
  int n;
  vector<int> p;

  dsu(int _n) : n(_n), p(n) {
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges;
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    --x; --y;
    edges.emplace_back(x, y, w);
  }
  sort(edges.begin(), edges.end(), [&](auto& ei, auto& ej) {
    return get<2>(ei) > get<2>(ej);
  });
  dsu d(n);
  long long sum = 0;
  vector<vector<pair<int, int>>> g(n);
  for (auto[v, u, w] : edges) {
    if (d.unite(v, u)) {
      sum += 2 * w;
      g[v].emplace_back(u, w);
      g[u].emplace_back(v, w);
    }
  }
  long long max_cost = 0;
  function<bool(int, int, long long)> DFS = [&](int v, int pr, long long cur_dist) {
    bool is_leaf = true;
    for (auto[u, w] : g[v]) {
      if (u != pr) {
        is_leaf = false;
        if (DFS(u, v, cur_dist + w)) {
          max_cost = max(max_cost, cur_dist + w);
        }
      }
    }
    return is_leaf;
  };
  int st;
  cin >> st;
  --st;
  DFS(st, -1, 0LL);
  cout << sum - max_cost << '\n';
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