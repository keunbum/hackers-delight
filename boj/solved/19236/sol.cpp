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
  const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
  const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
  array<array<array<int, 2>, 4>, 4> a;
  auto Get = [&](int k, int& x, int& y) {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        if (a[i][j][0] == k) {
          x = i;
          y = j;
          return true;
        }
      }
    }
    return false;
  };
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int k, dir;
      cin >> k >> dir;
      --k; --dir;
      a[i][j] = {k, dir};
    }
  }
  int ans = 0;
  auto DFS = [&](auto& self, int sx, int sy, int sdir, int cur) -> void {
    ans = max(ans, cur);
    auto ta(a);
    for (int i = 0; i < 16; ++i) {
      int x, y;
      if (!Get(i, x, y)) {
        continue;
      }
      int rep = 8;
      while (rep--) {
        int nx = x + dx[a[x][y][1]];
        int ny = y + dy[a[x][y][1]];
        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && !(nx == sx && ny == sy)) {
          swap(a[nx][ny], a[x][y]);
          break;
        }
        a[x][y][1] = (a[x][y][1] + 1) % 8;
      }
    }
    int nsx = sx;
    int nsy = sy;
    for (int rep = 0; rep < 3; ++rep) {
      nsx += dx[sdir];
      nsy += dy[sdir];
      if (nsx >= 0 && nsy >= 0 && nsx < 4 && nsy < 4 && a[nsx][nsy][0] != -1) {
        int id = a[nsx][nsy][0];
        a[nsx][nsy][0] = -1;
        self(self, nsx, nsy, a[nsx][nsy][1], cur + id + 1);
        a[nsx][nsy][0] = id;
      }
    }
    swap(a, ta);
  };
  auto[i, dir] = a[0][0];
  a[0][0][0] = -1;
  DFS(DFS, 0, 0, dir, i + 1);
  cout << ans << '\n';
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