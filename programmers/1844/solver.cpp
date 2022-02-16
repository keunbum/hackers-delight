#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> g) {
  int h = (int) g.size();
  int w = (int) g[0].size();
  vector<vector<int>> dist(h, vector<int>(w, -1));
  dist[0][0] = 0;
  vector<pair<int, int>> que(1, {0, 0});
  for (int b = 0; b < (int) que.size(); b++) {
    auto[i, j] = que[b];
    for (int dir = 0; dir < 4; dir++) {
      int ni = i + "2101"[dir] - '1';
      int nj = j + "1210"[dir] - '1';
      if (ni >= 0 && nj >= 0 && ni < h && nj < w && g[ni][nj] == 1 && dist[ni][nj] == -1) {
        dist[ni][nj] = dist[i][j] + 1;
        que.emplace_back(ni, nj);
      }
    }
  }
  return dist[h - 1][w - 1] == -1 ? -1 : dist[h - 1][w - 1] + 1;
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