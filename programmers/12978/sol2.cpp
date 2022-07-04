#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int n, vector<vector<int>> road, int k) {
  const int inf = (int) 1e9;
  vector<vector<pair<int, int>>> g(n);
  for (auto& v : road) {
    int x = v[0] - 1;
    int y = v[1] - 1;
    int z = v[2];
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
  }
  vector<int> dist(n, inf);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  int st = 0;
  dist[st] = 0;
  s.emplace(dist[st], st);
  while (!s.empty()) {
    auto[expected, v] = s.top();
    s.pop();
    if (expected != dist[v]) {
      continue;
    }
    for (auto&[u, cost] : g[v]) {
      if (dist[u] > dist[v] + cost) {
        dist[u] = dist[v] + cost;
        s.emplace(dist[u], u);
      }
    }
  }
  return count_if(dist.begin(), dist.end(), [&](int d) { return d <= k; });
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
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