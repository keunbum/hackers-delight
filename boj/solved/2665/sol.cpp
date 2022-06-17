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
  deque<pair<int, int>> due(1, {0, 0});
  vector<vector<int>> dist(n, vector<int>(n, -1));
  dist[0][0] = 0;
  while (!due.empty()) {
    auto[i, j] = due.front();
    if (i == n - 1 && j == n - 1) {
      cout << dist[n - 1][n - 1] << '\n';
      return 0;
    }  
    due.pop_front();
    for (int di : {-1, 0, 1}) {
      for (int dj : {-1, 0, 1}) {
        if (di * di + dj * dj == 1) {
          int ni = i + di;
          int nj = j + dj;
          if (ni >= 0 && ni < n && nj >= 0 && nj < n && dist[ni][nj] == -1) {
            if (a[ni][nj] == '1') {
              dist[ni][nj] = dist[i][j];
              due.emplace_front(ni, nj);
            } else {
              dist[ni][nj] = dist[i][j] + 1;
              due.emplace_back(ni, nj);
            }
          }
        }
      }
    }
  }
  assert(false);
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