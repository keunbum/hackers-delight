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
  const int di[] = {1, 0, -1, 0};
  const int dj[] = {0, 1, 0, -1};
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  int dir1 = 0;
  int si = 0;
  int sj = -1;
  for (int it = 0; it < 2 * (h + w); it++) {
    int dir2 = si < 0 ? 0 : (si >= h ? 2 : (sj < 0 ? 1 : 3));
    int i = si + di[dir2];
    int j = sj + dj[dir2];
    while (0 <= i && i < h && 0 <= j && j < w) {
      if (a[i][j]) {
        if (dir2 % 2 == 0) {
          dir2 = (dir2 + 3) % 4;
        } else {
          dir2 = (dir2 + 1) % 4;
        }
      }
      i += di[dir2];
      j += dj[dir2];
    }
    int ret = 0;
    ret += (j < 0) * (i + 1);
    ret += (i >= h) * (h + j + 1);
    ret += (j >= w) * (h + w + h - i);
    ret += (i < 0) * (h + w + h + w - j);
    cout << ret << " \n"[it == 2 * (h + w) - 1];
    si += di[dir1];
    sj += dj[dir1];
    if ((si < 0 || si >= h) && (sj < 0 || sj >= w)) {
      dir1 += 1;
      si += di[dir1];
      sj += dj[dir1];
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
  * deep breathing. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/