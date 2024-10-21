#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<vector<int>> a) {
  int h = (int) a.size();
  int w = (int) a[0].size();
  int mx = 0;
  vector<int> dp(w, 0);
  vector<int> row(w, 0);
  vector<int> col(w, 0);
  for (int i = 0; i < h; i++) {
    vector<int> new_dp(w);
    vector<int> new_col(w);
    if (a[i][0] == 0) {
      row[0] = col[0] = new_dp[0] = 0;
    } else {
      row[0] = new_dp[0] = 1;
      new_col[0] = col[0] + 1;
    }
    mx = max(mx, new_dp[0]);
    for (int j = 1; j < w; j++) {
      if (a[i][j] == 0) {
        row[j] = new_col[j] = new_dp[j] = 0;
      } else {
        row[j] = row[j - 1] + 1;
        new_col[j] = col[j] + 1;
        new_dp[j] = min({dp[j - 1], row[j - 1], col[j]}) + 1;
      }
      mx = max(mx, new_dp[j]);
    }
    swap(dp, new_dp);
    swap(col, new_col);
    debug(dp);
    debug(row);
    debug(col);
  }
  debug(mx);
  return mx * mx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}});
  solution({{0, 0, 1, 1}, {1, 1, 1, 1}});
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