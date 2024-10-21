#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int n, vector<vector<int>> results) {
  vector<vector<int>> g(n);
  vector<vector<int>> rev_g(n);
  vector<int> deg(n, 0);
  vector<int> rev_deg(n, 0);
  for (auto& e : results) {
    g[e[0] - 1].push_back(e[1] - 1);
    rev_g[e[1] - 1].push_back(e[0] - 1);
    deg[e[1] - 1] += 1;
  }
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      que.push_back(i);
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    int v = que[b];
    for (int u : g[v]) {
      if (--deg[u] == 0) {
        que.push_back(u);
      }
    }
  }
  vector<int> me(n, 0);
  {
    vector<bool> was(n, false);
    for (int b = 0; b < (int) que.size(); b++) {
      int v = que[b];
      for (int u : rev_g[v]) {
        if (!was[u]) {
          was[u] = true;
          me[v] += me[u] + 1;
        }
      }
    }
  }
  vector<int> him(n, 0);
  {
    vector<bool> was(n, false);
    for (int b = (int) que.size() - 1; b >= 0; b--) {
      int v = que[b];
      for (int u : g[v]) {
        if (!was[u]) {
          was[u] = true;
          him[v] += him[u] + 1;
        }
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < n; i++) {
    ret += (me[i] + him[i] == n - 1);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution(5, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}, {4, 3}});
  solution(3, {{1, 2}, {1, 3}, {2, 3}});
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