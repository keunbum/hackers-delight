#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int E;
    cin >> E;
    vector<string> a(E), b(E);
    vector<string> strs(2 * E);
    for (int i = 0; i < E; ++i) {
      cin >> a[i] >> b[i];
      strs[i + i] = a[i];
      strs[i + i + 1] = b[i];
    }
    sort(strs.begin(), strs.end());
    strs.resize(unique(strs.begin(), strs.end()) - strs.begin());
    int n = (int) strs.size();
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    function<int(int)> Get = [&](int x) {
      return x == p[x] ? x : (p[x] = Get(p[x]));
    };
    vector<int> sz(n, 1);
    for (int i = 0; i < E; ++i) {
      int x = (int) (lower_bound(strs.begin(), strs.end(), a[i]) - strs.begin());
      int y = (int) (lower_bound(strs.begin(), strs.end(), b[i]) - strs.begin());
      x = Get(x);
      y = Get(y);
      if (x != y) {
        sz[x] += sz[y];
        p[y] = x;
      }
      cout << sz[x] << '\n';
    }
  }
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