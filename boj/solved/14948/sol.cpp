#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  auto Encode = [&](int i, int j, int k) {
    return ((w * i + j) << 1) | k;
  };
  auto Decode = [&](int x) -> tuple<int, int, int> {
    int y = x >> 1;
    return {y / w, y % w, x & 1};
  };
  vector<vector<int>> a(h, vector<int>(w));
  int high = -1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
      high = max(high, a[i][j]);
    }
  }
  int low = a[0][0];
  while (low < high) {
    int mid = (low + high) >> 1;
    int st = Encode(0, 0, 1);
    vector<int> que(1, st);
    vector<bool> was(h * w * 2, false);
    was[st] = true;
    for (int b = 0; b < (int) que.size(); ++b) {
      auto[i, j, jump] = Decode(que[b]);
      for (int dir = 0; dir < 4; ++dir) {
        for (int t = 1; t <= 1 + jump; ++t) {
          int ni = i + t * ("2101"[dir] - '1');
          int nj = j + t * ("1210"[dir] - '1');
          int u = Encode(ni, nj, jump - t + 1);
          if (ni >= 0 && ni < h && nj >= 0 && nj < w && !was[u] && a[ni][nj] <= mid) {
            was[u] = true;
            que.push_back(u);
          }
        }
      }
    }
    if (was[Encode(h - 1, w - 1, 0)] || was[Encode(h - 1, w - 1, 1)]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';    
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