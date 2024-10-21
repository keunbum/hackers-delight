#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int md = (int) 1e9 + 7;

void Add(int& x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

int solution(int h, int w, vector<vector<int>> puddles) {
  vector<vector<bool>> wall(h, vector<bool>(w, false));
  for (auto& v : puddles) {
    wall[v[0] - 1][v[1] - 1] = true;
  }
  vector<vector<int>> dp(h, vector<int>(w, 0));
  dp[0][0] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if ((i == 0 && j == 0) || wall[i][j]) {
        continue;
      }
      if (i > 0) {
        Add(dp[i][j], dp[i - 1][j]);
      }
      if (j > 0) {
        Add(dp[i][j], dp[i][j - 1]);
      }
    }
  }
  return dp[h - 1][w - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
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