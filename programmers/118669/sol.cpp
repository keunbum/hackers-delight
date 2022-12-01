#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
  vector<int> bs(n, 0);
  for (int v : gates) {
    bs[v - 1] = 1;
  }
  vector<bool> is_summit(n, false);
  for (int v : summits) {
    bs[v - 1] = 2;
    is_summit[v - 1] = true;
  }
  const int inf = n;
  auto MinSummit = [&](vector<int>& path) {
    int x = path[0] - 1;
    int y = path[1] - 1;
    return min(is_summit[x] ? x : inf, is_summit[y] ? y : inf);
  };
  sort(paths.begin(), paths.end(), [&](auto& pi, auto& pj) {
    return pi[2] < pj[2] || (pi[2] == pj[2] && MinSummit(pi) < MinSummit(pj));
  });
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> Get = [&](int v) {
    return p[v] == v ? v : (p[v] = Get(p[v]));
  };
  vector<vector<int>> g(n);
  vector<int> starts;
  int bound = 0;
  for (auto& edge : paths) {
    if (bound > 0 && edge[2] > bound) {
      break;
    }
    int x = edge[0] - 1;
    int y = edge[1] - 1;
    g[x].push_back(y);
    g[y].push_back(x);
    int X = Get(x);
    int Y = Get(y);
    if (X != Y) {
      p[Y] = X;
      bs[X] |= bs[Y];
      if (bs[X] == 3) {
        bound = edge[2];
        starts.push_back(x);
      }
    }
  }
  assert(!starts.empty());
  vector<bool> was(n, false);
  vector<int> res;
  for (int st : starts) {
    was[st] = true;
    vector<int> que(1, st);
    for (int b = 0; b < (int) que.size(); b++) {
      int v = que[b];
      if (is_summit[v]) {
        res.push_back(v);
        continue;
      } 
      for (int u : g[v]) {
        if (!was[u]) {
          was[u] = true;
          que.push_back(u);
        }
      }
    }
  }
  assert(!res.empty());
  return {*min_element(res.begin(), res.end()) + 1, bound};   
}