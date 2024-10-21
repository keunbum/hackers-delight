#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

int solution(int n, int S, int A, int B, vector<vector<int>> edges) {
  --S; --A; --B;
  vector<vector<pair<int, int>>> g(n);
  for (auto& e : edges) {
    --e[0]; --e[1];
    g[e[0]].emplace_back(e[1], e[2]);
    g[e[1]].emplace_back(e[0], e[2]);
  }
  auto Dijkstra = [&](int st) {
    vector<int> dist(n, inf);
    dist[st] = 0;
    priority_queue<pair<int, int>> s;
    s.emplace(~dist[st], st);
    while (!s.empty()) {
      auto[expec, v] = s.top();
      s.pop();
      if (~expec != dist[v]) {
        continue;
      }
      for (auto[u, w] : g[v]) {
        if (dist[v] + w < dist[u]) {
          dist[u] = dist[v] + w;
          s.emplace(~dist[u], u);
        }
      }
    }
    return dist;
  };
  auto distS = Dijkstra(S);
  auto distA = Dijkstra(A);
  auto distB = Dijkstra(B);
  long long ans = inf;
  for (int K = 0; K < n; K++) {
    ans = min(ans, (long long) distS[K] + distA[K] + distB[K]);
  }
  return (int) ans;
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