#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

pair<int, int> Decode(int x) {
  --x;
  return { x / 3, x % 3 };
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  array<bool, 10> was{};
  function<void(int)> DFS = [&](int v) {
    was[a[v]] = true;
    if (v == n - 1) {
      cout << "YES" << endl;
      exit(0);
    }
    if (was[a[v + 1]]) return;
    auto[i, j] = Decode(a[v]);
    auto[ni, nj] = Decode(a[v + 1]);
    bool ok = false;
    {
      vector<pair<int, int>> que(1, {i, j});
      array<array<bool, 3>, 3> vis{};
      vis[i][j] = true;
      for (int b = 0; b < (int) que.size(); ++b) {
        auto[x, y] = que[b];
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            if (dx * dx + dy * dy != 0) {
              int nx = x + dx;
              int ny = y + dy;
              if (nx == ni && ny == nj) {
                ok = true;
                break;
              }
              if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3 && !vis[nx][ny] && was[nx * 3 + ny + 1]) {
                vis[nx][ny] = true;
                que.emplace_back(nx, ny);
              }
            }
          }
          if (ok) {
            break;
          }
        }
        if (ok) {
          break;
        }
      }
    }
    if (ok) {
      DFS(v + 1);
    }
  };
  DFS(0);
  cout << "NO" << endl;
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