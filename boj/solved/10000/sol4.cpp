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
  map<int, int> mp;
  vector<vector<int>> g;
  auto Get = [&](int x) {
    auto it = mp.find(x);
    if (it == mp.end()) {
      it = mp.insert({x, (int) g.size()}).first;
      g.emplace_back();
    }
    return it->second;
  };
  for (int i = 0; i < n; i++) {
    int x, r;
    cin >> x >> r;
    int v = Get(x - r);
    int u = Get(x + r);
    g[v].push_back(u);
    g[u].push_back(v);
  }
  int e = 2 * n;
  int v = (int) g.size();
  int ans = e - v + 1;
  vector<bool> was(2 * n, false);
  for (int i = 0; i < (int) g.size(); i++) {
    if (!was[i]) {
      ans += 1;
      vector<int> stk(1, i);
      was[i] = true;
      while (!stk.empty()) {
        int v = stk.back();
        stk.pop_back();
        for (int u : g[v]) {
          if (!was[u]) {
            was[u] = true;
            stk.push_back(u);
          }
        }
      }
    }
  }
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