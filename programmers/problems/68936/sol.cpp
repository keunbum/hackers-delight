#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> DFS(vector<vector<int>>& a, int si, int sj, int n) {
  bool ok = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ok &= a[si][sj] == a[si + i][sj + j];
    }
  }
  if (ok) {
    return {a[si][sj] == 0, a[si][sj] == 1};
  }
  int nn = n / 2;
  vector<int> ret{0, 0};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      auto v = DFS(a, si + i * nn, sj + j * nn, nn);
      ret[0] += v[0];
      ret[1] += v[1];
    }
  }
  return ret;
}

vector<int> solution(vector<vector<int>> a) {
  return DFS(a, 0, 0, (int) a.size());
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