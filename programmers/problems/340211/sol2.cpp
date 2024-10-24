﻿#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

const int N = 100;

array<array<unordered_map<int, int>, N>, N> a;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
  for (int i = 0; i < int(routes.size()); ++i) {
    int t = 0;
    auto Get = [&](int id) {
      auto& p = points[id - 1];
      return make_pair(p[0] - 1, p[1] - 1);
    };
    auto [mi, mj] = Get(routes[i][0]);
    int m = int(routes[i].size());
    for (int j = 1; j < m; ++j) {
      auto [ni, nj] = Get(routes[i][j]);
      while (mi < ni) {
        a[mi][mj][t++] += 1;
        mi += 1;
      }
      while (mi > ni) {
        a[mi][mj][t++] += 1;
        mi -= 1;
      }
      while (mj < nj) {
        a[mi][mj][t++] += 1;
        mj += 1;
      }
      while (mj > nj) {
        a[mi][mj][t++] += 1;
        mj -= 1;
      }
    }
    a[mi][mj][t++] += 1;
  }
  int ret = 0;
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      auto& mp = a[x][y];
      for (auto [_, cnt] : mp) {
        ret += (cnt > 1);
      }
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({{3, 2}, {6, 4}, {4, 7}, {1, 4}}, {{4, 2}, {1, 3}, {4, 2}, {4, 3}});
  solution({{2, 2}, {2, 3}, {2, 7}, {6, 6}, {5, 2}},	{{2, 3, 4, 5}, {1, 3, 4, 5}});
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
