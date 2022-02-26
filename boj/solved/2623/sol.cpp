#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> deg(n, 0);
  while (m--) {
    int t;
    cin >> t;
    int v;
    cin >> v;
    --v;
    while (--t) {
      int u;
      cin >> u;
      --u;
      g[u].push_back(v);
      deg[v] += 1;
      swap(u, v);
    }
  }
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      que.push_back(i);
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    int v = que[b];
    for (int pr : g[v]) {
      if (--deg[pr] == 0) {
        que.push_back(pr);
      }
    }
  }
  if ((int) que.size() != n) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = n - 1; i >= 0; i--) {
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