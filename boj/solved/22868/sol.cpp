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
  vector<vector<int>> g(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (auto& us : g) {
    sort(us.begin(), us.end(), [&](int i, int j) {
      return i < j;
    });
  }
  vector<bool> ignore(n, false);
  vector<int> prev(n, -1);
  auto BFS = [&](int st, int en) {
    vector<int> que(1, st);
    vector<int> dist(n, -1);
    dist[st] = 0;
    for (int b = 0; b < (int) que.size(); b++) {
      int v = que[b];
      for (int u : g[v]) {
        if (!ignore[u] && dist[u] == -1) {
          dist[u] = dist[v] + 1;
          prev[u] = v;
          que.push_back(u);
        }
      }
    }
    int v = en;
    while (prev[v] != st) {
      ignore[prev[v]] = true;
      v = prev[v];
    }
    return dist[en];
  };
  int S, E;
  cin >> S >> E;
  --S; --E;
  cout << BFS(S, E) + BFS(E, S) << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/