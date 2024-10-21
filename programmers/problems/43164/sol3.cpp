#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<string> solution(vector<vector<string>> tickets) {
  const int N = (int) 1e4;
  vector<vector<pair<int, bool>>> g(N);
  vector<string> names(N);
  map<string, int> mp;
  auto Get = [&](string name) {
    if (mp.find(name) == mp.end()) {
      mp[name] = (int) mp.size();
    }
    return mp[name];
  };
  for (auto& ticket : tickets) {
    int x = Get(ticket[0]);
    int y = Get(ticket[1]);
    names[x] = ticket[0];
    names[y] = ticket[1];
    g[x].emplace_back(y, true);
  }
  g.resize(mp.size());
  names.resize(mp.size());
  for (auto& edges : g) {
    sort(edges.begin(), edges.end(), [&](const pair<int, bool>& ei, const pair<int, bool>& ej) {
      return names[ei.first] < names[ej.first];
    });
  }
  int st = mp["ICN"];
  vector<string> stk;
  function<bool(int, int)> Dfs = [&](int v, int depth) {
    stk.push_back(names[v]);
    if (depth == (int) tickets.size()) {
      return true;
    }
    for (auto&[u, usable] : g[v]) {
      if (usable) {
        usable = false;
        if (Dfs(u, depth + 1)) {
          return true;
        }
        usable = true;
      }
    } 
    stk.pop_back();
    return false;
  };
  assert(Dfs(st, 0));
  return stk;
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