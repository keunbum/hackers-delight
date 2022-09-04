#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int Get(map<string, int>& mp, string s) {
  auto it = mp.find(s);
  if (it == mp.end()) {
    mp[s] = (int) mp.size();
  }
  return mp[s];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<string, int> mp1;
  map<string, int> mp2;
  const int N = 1001;
  vector<vector<int>> g(N);
  for (int _ = 0; _ < n + m; _++) {
    string p, f, c;
    cin >> p >> f >> c;
    int from = Get(mp1, p);
    int to;
    if (c == "0") {
      to = Get(mp2, f) + N;
    } else {
      to = Get(mp1, f);
    }
    g[from].push_back(to);
  }
  g.resize(mp1.size());
  vector<map<int, int>> dp(mp1.size());
  vector<bool> was(mp1.size(), false);
  function<map<int, int>(int)> Dfs = [&](int v) {
    if (was[v]) {
      return dp[v];
    }
    map<int, int> ret;
    for (int u : g[v]) {
      if (u < N) {
        auto t = Dfs(u);
        for (auto[x, y] : t) {
          ret[x] += y;
        }
      } else {
        ret[u] += 1;
      }
    }
    was[v] = true;
    return dp[v] = ret;
  };
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    int i = t.rfind('/');
    string s = t.substr(i + 1);
    auto res = Dfs(mp1[s]);
    int kind = 0;
    int cnt = 0;
    for (auto[x, y] : res) {
      kind += 1;
      cnt += y;
    }
    cout << kind << " " << cnt << '\n';
  }
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