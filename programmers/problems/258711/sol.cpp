#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

const int N = int(1e6);

int in[N], out[N];
vector<int> g[N];

vector<int> solution(vector<vector<int>> edges) {
  for (auto& edge : edges) {
    int x = edge[0] - 1;
    int y = edge[1] - 1;
    in[y] += 1;
    out[x] += 1;
    g[x].push_back(y);
  }
  int root = -1;
  for (int i = 0; i < N; ++i) {
    if (in[i] == 0 && out[i] >= 2) {
      root = i;
      break;
    }
  }
  assert(root != -1);
  int x = 0, y = 0, z = 0;
  vector<bool> was(N, false);
  for (int r : g[root]) {
    int V = 0;
    int E = 0;
    auto DFS = [&](auto&& self, int v) -> void {
      if (was[v]) {
        return;
      }
      was[v] = true;
      V += 1;
      for (int u : g[v]) {
        E += 1;
        self(self, u);
      }
    };    
    DFS(DFS, r);
    x += (E == V);
    y += (E == V - 1);
    z += (E == V + 1);
  }
  return {root + 1, x, y, z};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
//  solution({{2, 3}, {4, 3}, {1, 1}, {2, 1}});
  solution({{4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11}, {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}, {4, 6}});
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * Do I have to solve like this?
  
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
