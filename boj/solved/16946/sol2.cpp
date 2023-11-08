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
  const int di[] = {1, 0, -1, 0};
  const int dj[] = {0, 1, 0, -1};
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; ++i) {
    cin >> s[i];
  }
  vector<int> cnts;
  vector<vector<int>> was(h, vector<int>(w, -1));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '0' && was[i][j] == -1) {
        was[i][j] = (int) cnts.size();
        vector<array<int, 2>> que(1, {i, j});
        for (int b = 0; b < (int) que.size(); ++b) {
          auto[mi, mj] = que[b];
          for (int dir = 0; dir < 4; ++dir) {
            int ni = mi + di[dir];
            int nj = mj + dj[dir];
            if (0 <= ni && ni < h && 0 <= nj && nj < w && s[ni][nj] == '0' && was[ni][nj] == -1) {
              was[ni][nj] = was[i][j];
              que.push_back({ni, nj});
            }
          }
        }
        cnts.push_back(que.size());
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '1') {
        set<int> ss;
        for (int dir = 0; dir < 4; ++dir) {
          int ni = i + di[dir];
          int nj = j + dj[dir];
          if (0 <= ni && ni < h && 0 <= nj && nj < w && s[ni][nj] == '0') {
            ss.insert(was[ni][nj]);
          }
        }
        int sum = 0;
        for (int i : ss) {
          sum += cnts[i];
        }
        s[i][j] = (char) ((sum + 1) % 10 + '0');
      }
    }
    cout << s[i] << '\n';
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