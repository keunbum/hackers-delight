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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  vector<array<int, 3>> que;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      if (a[i][j] != 0) {
        que.push_back({a[i][j], i, j});
      }
    }
  }
  sort(que.begin(), que.end(), [&](const auto& l, const auto& r) {
    return l[0] < r[0];
  });
  const int di[] = {1, 0, -1, 0};
  const int dj[] = {0, 1, 0, -1};
  int s;
  cin >> s;
  while (s--) {
    vector<array<int, 3>> nque;
    for (int b = 0; b < int(que.size()); ++b) {
      auto[id, i, j] = que[b];
      for (int dir = 0; dir < 4; ++dir) {
        int ni = i + di[dir];
        int nj = j + dj[dir];
        if (ni >= 0 && nj >= 0 && ni < n && nj < n && a[ni][nj] == 0) {
          a[ni][nj] = id;
          nque.push_back({id, ni, nj});
        }
      }
    }
    swap(que, nque);
  }
  int x, y;
  cin >> x >> y;
  --x; --y;
  cout << a[x][y] << '\n';
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
