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
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int inf = (int) 1e9;
  vector<vector<int>> dist(n, vector<int>(n, inf));
  dist[0][0] = 0;
  priority_queue<pair<int, int>> s;
  s.emplace(~0, 0 * n + 0);
  while (!s.empty()) {
    auto[expec, k] = s.top();
    s.pop();
    int i = k / n;
    int j = k % n;
    if (~expec != dist[i][j]) continue;
    for (int dir = 0; dir < 4; dir++) {
      int ni = i + "2101"[dir] - '1';
      int nj = j + "1210"[dir] - '1';
      if (min(ni, nj) < 0 || max(ni, nj) >= n || dist[ni][nj] <= dist[i][j]) continue;
      dist[ni][nj] = dist[i][j] + (a[ni][nj] == '0');
      s.emplace(~dist[ni][nj], ni * n + nj);
    }
  }
  cout << dist[n - 1][n - 1] << '\n';
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