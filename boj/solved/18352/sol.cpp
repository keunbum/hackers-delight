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
  int n, m, k, x;
  cin >> n >> m >> k >> x;
  --x;
  vector<vector<int>> g(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
  }
  vector<bool> was(n, false);
  was[x] = true;
  vector<int> que(1, x);
  for (int rot = 0; rot < k; rot++) {
    vector<int> new_que;
    debug(que);
    for (int v : que) {
      for (int u : g[v]) {
        if (!was[u]) {
          was[u] = true;
          new_que.push_back(u);
        }
      }
    }
    swap(que, new_que);
  }
  debug(que);
  if (que.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  sort(que.begin(), que.end());
  for (int i = 0; i < (int) que.size(); i++) {
    cout << que[i] + 1 << '\n';
  }
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