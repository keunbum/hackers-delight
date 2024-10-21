#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

const int N = int(1e6);

int in[N], out[N];

class dsu {
public:
  int n;
  vector<int> p;
  vector<int> V;
  vector<int> E;

  dsu(int _n) : n(_n), p(n), V(n, 1), E(n, 0) {
    iota(p.begin(), p.end(), 0);
  }

  int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    E[y] += 1;
    if (x != y) {
      p[x] = y;
      V[y] += V[x];
      E[y] += E[x];
      return true;
    }
    return false;
  }
};

vector<int> solution(vector<vector<int>> edges) {
  int n = 0;
  for (auto& edge : edges) {
    int x = edge[0] - 1;
    int y = edge[1] - 1;
    out[x] += 1;
    in[y] += 1;
    n = max({n, x + 1, y + 1});    
  }
  int root = -1;
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0 && out[i] >= 2) {
      root = i;
      break;
    }
  }
  dsu d(n);
  vector<bool> ok(n, false);
  for (auto& edge : edges) {
    int x = edge[0] - 1;
    int y = edge[1] - 1;
    ok[y] = true;
    if (x == root) {
      continue;
    }
    ok[x] = true;
    d.unite(y, x);
  }
  int x = 0, y = 0, z = 0;
  vector<bool> was(n, false);
  for (int i = 0; i < n; ++i) {
    int p = d.get(i);
    if (ok[i] && !was[p]) {
      was[p] = true;
      int V = d.V[p];
      int E = d.E[p];
      x += (E == V);
      y += (E == V - 1);
      z += (E == V + 1);
    }
  }
  return {root + 1, x, y, z};
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
