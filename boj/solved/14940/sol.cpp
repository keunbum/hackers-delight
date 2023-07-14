#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  int si = -1, sj = -1;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 2) {
        si = i;
        sj = j;
      }
    }
  }
  vector<vector<int>> dist(h, vector<int>(w, -1));
  vector<pair<int, int>> que{{si, sj}};
  dist[si][sj] = 0;
  for (int b = 0; b < (int) que.size(); ++b) {
    auto[i, j] = que[b];
    for (int di = -1; di <= 1; ++di) {
      for (int dj = -1; dj <= 1; ++dj) {
        if (di * di + dj * dj == 1) {
          int ni = i + di;
          int nj = j + dj;
          if (ni >= 0 && nj >= 0 && ni < h && nj < w && a[i][j] != 0 && dist[ni][nj] == -1) {
            dist[ni][nj] = dist[i][j] + 1;
            que.emplace_back(ni, nj);
          }
        }
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << (a[i][j] == 0 ? 0 : dist[i][j]) << " \n"[j == w - 1];
    }
  } 
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