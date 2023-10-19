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
    int v = edge[0] - 1;
    int u = edge[1] - 1;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  auto Encode = [&](int t, int v) {
    return t * n + v;
  };
  const int inf = (int) 1e8;
  vector<int> dist(k * n, inf);
  int start_state = Encode(0, gps_log[0]);
  dist[start_state] = 0;
  s.emplace(dist[0], start_state);
  dist[start_state] = 0;
  while (!s.empty()) {
    auto[expected, state] = s.top();
    s.pop();
    if (expected != dist[state]) {
      continue;
    }
    int t = state / n;
    if (t == k - 1) {
      return dist[state];
    }
    int v = state % n;
    for (int u : g[v]) {
      int nstate = Encode(t + 1, u);
      if (u == gps_log[t + 1]) {
        if (dist[nstate] > dist[state]) {
          dist[nstate] = dist[state];
          s.emplace(dist[nstate], nstate); 
        }
      } else {
        if (t + 1 == k - 1) {
          continue;
        }
        if (dist[nstate] > dist[state] + 1) {
          dist[nstate] = dist[state] + 1;
          s.emplace(dist[nstate], nstate);
        }
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto res1 = solution(7, 10, {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}}, 6, {1, 2, 3, 3, 6, 7});
  debug(res1);
  auto res2 = solution(7, 10, {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}}, 6, {1, 2, 4, 6, 5, 7});
  debug(res2);
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