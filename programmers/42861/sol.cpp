#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int n, vector<vector<int>> costs) {
  int ret = 0;
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> Get = [&](int v) {
    return v == p[v] ? v : p[v] = Get(p[v]);
  };
  sort(costs.begin(), costs.end(), [&](auto& ci, auto& cj) {
    return ci[2] < cj[2];
  });
  for (auto& edge : costs) {
    int x = Get(edge[0]);
    int y = Get(edge[1]);
    if (x != y) {
      p[x] = y;
      ret += edge[2];
    }
  }
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
  * deep breathing. keep calm
  
 * stuff you should look for
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