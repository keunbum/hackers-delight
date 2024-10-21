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
  vector<int> b(n + n);
  for (int i = 0; i < n; i++) {
    int x, r;
    cin >> x >> r;
    a[i + i] = b[i + i] = x - r;
    a[i + i + 1] = b[i + i + 1] = x + r;
  }
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  debug(a);
  debug(b);
  int V = (int) b.size();
  int C = V;
  vector<int> p(V);
  iota(p.begin(), p.end(), 0);
  function<int(int)> Get = [&](int v) { return v == p[v] ? v : p[v] = Get(p[v]); };
  for (int i = 0; i < n; i++) {
    int v = (int) (lower_bound(b.begin(), b.end(), a[i + i]) - b.begin());
    int u = (int) (lower_bound(b.begin(), b.end(), a[i + i + 1]) - b.begin());
    v = Get(v);
    u = Get(u);
    if (v != u) {
      p[v] = u;
      C -= 1;
    }
  }
  int E = 2 * n;
  int ans = E - V + C + 1;
  cout << ans << '\n';
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