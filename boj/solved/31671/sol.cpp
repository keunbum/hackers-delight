#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> wall(n + n + 1, vector<bool>(n + 1, false));
  while (m--) {
    int x, y;
    cin >> x >> y;
    wall[x][y] = true;
  }
  vector<vector<int>> best(n + n + 1, vector<int>(n + 1, -1));
  vector<array<int, 2>> que{{0, 0}};
  best[0][0] = 0;
  for (int b = 0; b < int(que.size()); ++b) {
    auto [mx, my] = que[b];
    for (auto [nx, ny] : vector<array<int, 2>>{{mx + 1, my + 1}, {mx + 1, my - 1}}) {
      if (ny >= 0 && abs(nx - n) + abs(ny - 0) <= n && !wall[nx][ny]) {
        if (best[nx][ny] == -1) {
          que.push_back({nx, ny});
        }
        best[nx][ny] = max({best[nx][ny], ny, best[mx][my]});
      }
    }
  }
  cout << best[n + n][0] << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * Do I have to solve like this?
  
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