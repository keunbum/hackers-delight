#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<string> solution(vector<vector<string>> tickets) {
  map<string, vector<pair<string, bool>>> g;
  for (auto& ticket : tickets) {
    g[ticket[0]].emplace_back(ticket[1], false);
  }
  for (auto&[_, edges] : g) {
    sort(edges.begin(), edges.end(), [&](auto& ei, auto& ej) {
      auto&[v, _i] = ei;
      auto&[u, _j] = ej;
      return v < u;
    });
  }
  vector<string> path;
  function<bool(string)> DFS = [&](string v) {
    path.push_back(v);
    if (path.size() - 1 == tickets.size()) {
      return true;
    }
    for (auto&[u, used] : g[v]) {
      if (!used) {
        used = true;
        if (DFS(u)) {
          return true;
        }
        used = false;
      }
    }
    path.pop_back();
    return false;
  };
  assert(DFS("ICN"));
  return path;
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