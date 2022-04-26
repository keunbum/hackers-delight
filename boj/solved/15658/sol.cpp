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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  array<int, 4> b;
  for (int i = 0; i < 4; i++) {
    cin >> b[i];
  }
  const int inf = (int) 2e9;
  int mx = -inf;
  int mn = inf;
  function<void(int, int)> Dfs = [&](int v, int w) {
    if (v == n - 1) {
      mx = max(mx, w);
      mn = min(mn, w);
      return;
    }
    for (int i = 0; i < 4; i++) {
      if (b[i] == 0) {
        continue;
      }
      int nw = w;
      if (i == 0) nw += a[v + 1]; else
      if (i == 1) nw -= a[v + 1]; else
      if (i == 2) nw *= a[v + 1]; else
      if (i == 3) nw /= a[v + 1];
      b[i] -= 1;
      Dfs(v + 1, nw);
      b[i] += 1;
    }
  };
  Dfs(0, a[0]);
  cout << mx << "\n" << mn << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
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