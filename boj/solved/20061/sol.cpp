#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

using Grid = array<array<int, 4>, 6>;
using MinoSize = array<int, 2>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Grid a{}, b{};
  int score = 0;
  auto Solve = [&](Grid& g, int j, MinoSize mino_sz) {
    {
      int i = 0;
      while (true) {
        bool ok = true;
        for (int di = 0; di < mino_sz[0]; ++di) {
          for (int dj = 0; dj < mino_sz[1]; ++dj) {
            int ni = (i + 1) + di;
            int nj = j + dj;
            ok &= (ni < 6 && g[ni][nj] == 0);
          }
        }
        if (!ok) {
          break;
        }
        i += 1;
      }
      for (int di = 0; di < mino_sz[0]; ++di) {
        for (int dj = 0; dj < mino_sz[1]; ++dj) {
          g[i + di][j + dj] = 1;
        }
      }
    }
    auto Push = [&](int si, int by) {
      for (int i = si; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
          g[i][j] = (i - by >= 0 ? g[i - by][j] : 0);
        }
      }
    };
    {
      int lines = 0;
      int ei = 5;
      for (int i = 2; i < 6; ++i) {
        if (g[i] == array<int, 4>{1, 1, 1, 1}) {
          lines += 1;
          ei = i;
        }
      }
      score += lines;
      Push(ei, lines);
    }
    {
      int cnt = 0;
      for (int i = 0; i < 2; ++i) {
        cnt += g[i] != array<int, 4>{};
      }
      Push(5, cnt);
    }
  };
  int T;
  cin >> T;
  while (T--) {
    const MinoSize ONE = {1, 1};
    const MinoSize ONETWO = {1, 2};
    const MinoSize TWOONE = {2, 1};
    int t, i, j;
    cin >> t >> i >> j;
    if (t == 1) {
      Solve(a, j, ONE);
      Solve(b, 3 - i, ONE);
    }
    if (t == 2) {
      Solve(a, j, ONETWO);
      Solve(b, 3 - i, TWOONE);
    }
    if (t == 3) {
      Solve(a, j, TWOONE);
      Solve(b, 3 - i - 1, ONETWO);
    }
  }
  int cnt = 0;
  for (Grid g : {a, b}) {
    for (auto& r : g) {
      for (int x : r) {
        cnt += x;
      }
    }
  }
  cout << score << '\n' << cnt << '\n';
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