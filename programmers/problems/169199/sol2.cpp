#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

const int N = 100;
const int di[] = {0, 1, 0, -1};
const int dj[] = {-1, 0, 1, 0};

pair<int, int> nxt[N][N][4];

int solution(vector<string> grid) {
  int h = int(grid.size());
  int w = int(grid[0].size());
  int si = -1, sj = -1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] == 'R') {
        si = i;
        sj = j;
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] == 'D') continue;
      if (j == 0) nxt[i][j][0] = {i, j};
      else nxt[i][j][0] = (grid[i][j - 1] == 'D' ? make_pair(i, j) : nxt[i][j - 1][0]);
    }
    for (int j = w - 1; j >= 0; --j) {
      if (grid[i][j] == 'D') continue;
      if (j == w - 1) nxt[i][j][2] = {i, j};
      else nxt[i][j][2] = (grid[i][j + 1] == 'D' ? make_pair(i, j) : nxt[i][j + 1][2]);
    }
  }
  for (int j = 0; j < w; ++j) {
    for (int i = 0; i < h; ++i) {
      if (grid[i][j] == 'D') continue;
      if (i == 0) nxt[i][j][1] = {i, j};
      else nxt[i][j][1] = (grid[i - 1][j] == 'D' ? make_pair(i, j) : nxt[i - 1][j][1]);
    }
    for (int i = h - 1; i >= 0; --i) {
      if (grid[i][j] == 'D') continue;
      if (i == h - 1) nxt[i][j][3] = {i, j};
      else nxt[i][j][3] = (grid[i + 1][j] == 'D' ? make_pair(i, j) : nxt[i + 1][j][3]);
    }
  }
  vector<array<int, 2>> que{{si, sj}};
  vector<vector<bool>> was(h, vector<bool>(w, false));
  was[si][sj] = true;
  for (int iter = 0; !que.empty(); ++iter) {
    vector<array<int, 2>> nque;
    for (auto [mi, mj] : que) {
      for (int dir = 0; dir < 4; ++dir) {
        auto [ni, nj] = nxt[mi][mj][dir];
        if (grid[ni][nj] == 'G') {
          return iter + 1;
        }
        if (!was[ni][nj]) {
          was[ni][nj] = true;
          nque.push_back({ni, nj});
        }
      }
    }
    swap(que, nque);
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
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
