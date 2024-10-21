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
  array<array<int, 5>, 5> a;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  int r, c;
  cin >> r >> c;
  vector<tuple<int, int, int>> que(1, {r, c, 0});
  a[r][c] = -1;
  for (int b = 0; b < (int) que.size(); b++) {
    auto[i, j, k] = que[b];
    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        if (di * di + dj * dj == 1) {
          int ni = i + di;
          int nj = j + dj;
          if (min(ni, nj) >= 0 && max(ni, nj) < 5 && a[ni][nj] != -1) {
            if (a[ni][nj] == 1) {
              cout << k + 1 << '\n';
              return 0;
            }
            a[ni][nj] = -1;
            que.emplace_back(ni, nj, k + 1);
          }
        }
      }
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