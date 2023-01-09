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
  int N, A, B;
  cin >> N >> A >> B;
  int n = 8 - N;
  int a = max(66 - A, 0);
  int b = max(130 - B, 0);
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(a + 1, vector<int>(b + 1, -1)));
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  function<bool(int, int, int)> DFS = [&](int i, int j, int k) {
    if (j == 0 && k == 0) {
      return 1;
    }
    if (i == n) {
      return 0;
    }
    if (dp[i][j][k] >= 0) {
      return dp[i][j][k];
    }
    dp[i][j][k] = 0;
    for (int ii = 0; ii <= x[i]; ii++) {
      for (int jj = 0; jj <= y[i]; jj++) {
        if (ii + jj <= 6) {
          dp[i][j][k] |= DFS(i + 1, max(j - 3 * ii, 0), max(k - (3 * ii + 3 * jj), 0));
        }
      }
    }
    return dp[i][j][k];
  };
  cout << (DFS(0, a, b) ? "Nice" : "Nae ga wae") << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/