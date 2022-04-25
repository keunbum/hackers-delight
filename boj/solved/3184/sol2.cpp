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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int total_os = 0;
  int total_vs = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        continue;
      }
      bool ok = true;
      int os = 0;
      int vs = 0;
      os += (s[i][j] == 'o');
      vs += (s[i][j] == 'v');
      s[i][j] = '#';
      vector<pair<int, int>> que(1, make_pair(i, j));
      for (int b = 0; b < (int) que.size(); b++) {
        for (int dir = 0; dir < 4; dir++) {
          int ni = que[b].first + "2101"[dir] - '1';
          int nj = que[b].second + "1210"[dir] - '1';
          if (ni < 0 || nj < 0 || ni >= h || nj >= w) {
            ok = false;
            break;
          }
          if (s[ni][nj] == '#') {
            continue;
          }
          os += (s[ni][nj] == 'o');
          vs += (s[ni][nj] == 'v');
          s[ni][nj] = '#';
          que.emplace_back(ni, nj);
        }
        if (!ok) {
          break;
        }
      }
      if (ok) {
        (os > vs ? vs : os) = 0;
        total_os += os;
        total_vs += vs;
      }
    }
  }
  cout << total_os << " " << total_vs << '\n';
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