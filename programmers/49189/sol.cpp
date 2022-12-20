#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int n, vector<vector<int>> edge) {
  vector<vector<int>> g(n);
  for (auto& e : edge) {
    g[e[0] - 1].push_back(e[1] - 1);
    g[e[1] - 1].push_back(e[0] - 1);
  }
  vector<int> que(1, 0);
  vector<bool> was(n, false);
  was[0] = true;
  while (!que.empty()) {
    vector<int> new_que;
    for (int v : que) {
      for (int u : g[v]) {
        if (!was[u]) {
          was[u] = true;
          new_que.push_back(u);
        }
      }
    }
    if (new_que.empty()) {
      return que.size();
    }
    swap(que, new_que);
  }
  assert(false);
  return -1;
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