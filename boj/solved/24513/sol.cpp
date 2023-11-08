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
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  vector<vector<int>> was(h, vector<int>(w, 0));
  vector<pair<int, int>> que;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
      if (a[i][j] > 0) {
        was[i][j] = 2;
        que.emplace_back(i, j);
      }
    }
  }
  while (!que.empty()) {
    vector<pair<int, int>> nque;
    for (auto[i, j] : que) {
      if (a[i][j] == 3) {
        continue;
      }
      for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
          if (di * di + dj * dj == 1) {
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && nj >= 0 && ni < h && nj < w && a[ni][nj] != -1 && was[ni][nj] != 2) {
              a[ni][nj] |= a[i][j];
              if (was[ni][nj] == 0) {
                was[ni][nj] = 1;
                nque.emplace_back(ni, nj);
              }
            }
          }
        }
      }
    }
    swap(que, nque);
    for (auto[i, j] : que) {
      was[i][j] = 2;
    }
  }
  int x = 0;
  int y = 0;
  int z = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      x += a[i][j] == 1;
      y += a[i][j] == 2;
      z += a[i][j] == 3;
    }
  }
  cout << x << " " << y << " " << z << '\n';
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