#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  vector<pair<int, int>> que;
  int ji, jj;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'J') {
        ji = i;
        jj = j;
      }
      if (s[i][j] == 'F') {
        que.emplace_back(i, j);
      }
    }
  }
  que.emplace(que.begin(), ji, jj);
  int iter = 0;
  while (!que.empty()) {
    debug(iter);
    for (int i = 0; i < h; i++) {
      debug(s[i]);
    }
    vector<pair<int, int>> new_que;
    for (int b = 0; b < (int) que.size(); b++) {
      auto[mi, mj] = que[b];
      if (s[mi][mj] == 'J') {
        for (int dir = 0; dir < 4; dir++) {
          int ni = mi + di[dir];
          int nj = mj + dj[dir];
          if (ni < 0 || nj < 0 || ni >= h || nj >= w) {
            cout << iter + 1 << '\n';
            return 0;
          }
          if (s[ni][nj] != '.') {
            continue;
          }
          s[ni][nj] = 'J';
          new_que.emplace_back(ni, nj);
        }
      }
      if (s[mi][mj] == 'F') {
        for (int dir = 0; dir < 4; dir++) {
          int ni = mi + di[dir];
          int nj = mj + dj[dir];
          if (ni < 0 || nj < 0 || ni >= h || nj >= w || s[ni][nj] == '#' || s[ni][nj] == 'F') {
            continue;
          }
          s[ni][nj] = 'F';
          new_que.emplace_back(ni, nj);
        }      
      }
    }
    swap(que, new_que);
    iter += 1;
  }
  cout << "IMPOSSIBLE" << '\n';
  return 0;
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