#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int n, vector<vector<int>> wires) {
  vector<vector<int>> g(n);
  for (auto& wire : wires) {
    int x = wire[0] - 1;
    int y = wire[1] - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ret = n;
  function<int(int, int)> Dfs = [&](int v, int pr) {
    int sz = 1;
    for (int u : g[v]) {
      if (u != pr) {
        int csz = Dfs(u, v);
        ret = min(ret, abs(n - 2 * csz));
        sz += csz;
      }
    }
    return sz;
  };
  Dfs(0, -1);
  return ret;
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