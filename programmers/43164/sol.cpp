#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<string> solution(vector<vector<string>> tickets) {
  map<string, int> mp;
  auto GetId = [&](const string& s) {
    if (mp.find(s) == mp.end()) {
      mp[s] = mp.size();
    }
    return mp[s];
  };
  const int MAX_N = (int) 1e4;
  vector<vector<pair<int, bool>>> g(MAX_N);
  vector<string> names(MAX_N);
  for (auto& ticket : tickets) {
    int x = GetId(ticket[0]);
    int y = GetId(ticket[1]);
    names[x] = ticket[0];
    names[y] = ticket[1];
    g[x].emplace_back(y, false);
  }
  int m = (int) tickets.size();
  int n = (int) mp.size();
  g.resize(n);
  names.resize(n);
  for (auto& edges : g) {
    sort(edges.begin(), edges.end(), [&](const auto& ei, const auto& ej) {
      auto[v, _i] = ei;
      auto[u, _j] = ej;
      return names[v] < names[u];
    });
  }
  vector<string> path;
  function<bool(int)> DFS = [&](int v) {
    path.push_back(names[v]);
    if ((int) path.size() - 1 == m) {
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
  assert(DFS(mp["ICN"]));
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