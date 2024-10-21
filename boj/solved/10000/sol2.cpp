#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + n);
  vector<pair<int, int>> e(n + n);
  for (int i = 0; i < n; i++) {
    int x, r;
    cin >> x >> r;
    a[i + i] = x - r;
    e[i + i] = {x - r, i + i};
    a[i + i + 1] = x + r;
    e[i + i + 1] = {x + r, i + i + 1};
  }
  sort(e.begin(), e.end());
  int t = 0;
  for (int i = 0; i < n + n; i++) {
    if (i > 0 && e[i].first != e[i - 1].first) {
      t += 1;
    }
    a[e[i].second] = t;
  }
  int V = t + 1;
  int C = V;
  vector<int> p(V);
  iota(p.begin(), p.end(), 0);
  function<int(int)> Get = [&](int v) { return v == p[v] ? v : p[v] = Get(p[v]); };
  for (int i = 0; i < n; i++) {
    int v = Get(a[i + i]);
    int u = Get(a[i + i + 1]);
    if (v != u) {
      p[v] = u;
      C -= 1;
    }
  }
  cout << C + 1 + 2 * n - V << '\n';
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