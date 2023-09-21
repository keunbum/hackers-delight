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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<bool>> wall(n, vector<bool>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      wall[i][j] = (bool) x;
    }
  }
  int ti, tj;
  cin >> ti >> tj;
  --ti; --tj;
  vector<array<int, 4>> pos(m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> pos[i][j];
      --pos[i][j];
    }
  }
  sort(pos.begin(), pos.end());
  const int INF = (int) 2e8;
  auto BFS = [&](int si, int sj) {
    vector<vector<int>> dist(n, vector<int>(n, INF));
    dist[si][sj] = 0;
    vector<array<int, 2>> que{{si, sj}};
    for (int b = 0; b < (int) que.size(); b++) {
      auto[i, j] = que[b];
      for (int dir = 0; dir < 4; ++dir) {
        int ni = i + "2101"[dir] - '1';
        int nj = j + "1210"[dir] - '1';
        if (ni >= 0 && nj >= 0 && ni < n && nj < n && !wall[ni][nj] && dist[ni][nj] == INF) {
          dist[ni][nj] = dist[i][j] + 1;
          que.push_back({ni, nj});
        }
      }
    }
    return dist;
  };
  vector<bool> was(m, false);
  int _ = m;
  while (_--) {
    int id = -1;
    {
      auto dist = BFS(ti, tj);
      int mn = INF;
      for (int i = 0; i < m; ++i) {
        if (!was[i] && dist[pos[i][0]][pos[i][1]] < mn) {
          mn = dist[pos[i][0]][pos[i][1]];
          id = i;
        }
      }
      if (k < mn) {
        cout << -1 << '\n';
        return 0;
      }
      was[id] = true;
      k -= mn;
    }
    {
      auto[si, sj, ei, ej] = pos[id];
      int cost = BFS(si, sj)[ei][ej];
      if (k < cost) {
        cout << -1 << '\n';
        return 0;
      }
      k += cost;
      ti = ei;
      tj = ej;
    }
  }
  cout << k << '\n';
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