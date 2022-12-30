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
  vector<vector<int>> a(n, vector<int>(n, -1));
  for (int it = 0; it < n; it++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    a[x][y] = it % 2;
    bool ok = false;
    for (auto[_di, _dj] : vector<pair<int, int>>{{0, 1}, {1, 0}, {1, 1}, {1, -1}}) {
      int cnt = 1;
      for (auto[di, dj] : vector<pair<int, int>>{{_di, _dj}, {-_di, -_dj}}) {
        int i = x + di;
        int j = y + dj;
        while (min(i, j) >= 0 && max(i, j) < n && a[i][j] == a[x][y]) {
          cnt += 1;
          i += di;
          j += dj;
        }
      }
      ok |= cnt == 5;
    }
    if (ok) {
      cout << (it + 1) << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/