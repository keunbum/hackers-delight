#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<int> solution(vector<string> s, vector<string> cmds) {
  int h = (int) s.size();
  int w = (int) s[0].size();
  int x = -1, y = -1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == 'S') {
        x = i;
        y = j;
      }
    }
  }
  for (string cmd : cmds) {
    int rep = (int) (cmd[2] - '0');
    int nx = x;
    int ny = y;
    bool ok = true;
    while (rep--) {
      if (cmd[0] == 'N') nx -= 1;
      if (cmd[0] == 'S') nx += 1;
      if (cmd[0] == 'W') ny -= 1;
      if (cmd[0] == 'E') ny += 1;
      if (nx < 0 || ny < 0 || nx >= h || ny >= w || s[nx][ny] == 'X') {
        ok = false;
        break;
      }
    }
    if (ok) {
      x = nx;
      y = ny;
    }
  }
  return {x, y};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({"SOO", "OXX", "OOO"}, {"E 2", "S 2", "W 1"});
  solution( {"OSO", "OOO", "OXO", "OOO"}, {"E 2", "S 3", "W 1"});
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