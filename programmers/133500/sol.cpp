#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

const int N = (int) 1e5;

vector<int> g[N];
bool turn_on[N];

int solution(int, vector<vector<int>> edges) {
  for (auto& edge : edges) {
    int x = edge[0] - 1;
    int y = edge[1] - 1;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ret = 0;
  function<void(int, int)> DFS = [&](int v, int pr) {
    for (int u : g[v]) {
      if (u != pr) {
        DFS(u, v);
        turn_on[v] |= !turn_on[u];
      }
    }
    ret += turn_on[v];
  };
  DFS(0, -1);
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