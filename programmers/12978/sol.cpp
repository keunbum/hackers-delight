#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int N, vector<vector<int> > road, int K) {
  const int inf = (int) 1e9;
  vector<vector<int>> dp(N, vector<int>(N, inf));
  for (int i = 0; i < N; i++) {
    dp[i][i] = 0;
  }
  for (auto& v : road) {
    int x = v[0] - 1;
    int y = v[1] - 1;
    int z = v[2];
    dp[x][y] = min(dp[x][y], z);
    dp[y][x] = min(dp[y][x], z);
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      if (dp[i][k] == inf) continue;
      for (int j = 0; j < N; j++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  return count_if(dp[0].begin(), dp[0].end(), [&](int v) { return v <= K; });
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
  * keep calm
  
 * stuff you should look for
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