#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int n, vector<vector<int>> c) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (c[i][k] == 0) continue;
      for (int j = 0; j < n; j++) {
        c[i][j] |= c[i][k] & c[k][j];
      }
    }
  }
  int ret = 0;
  vector<bool> used(n, false);
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    ret += 1;
    used[i] = true;
    for (int j = 0; j < n; j++) {
      if (c[i][j] && !used[j]) {
        used[j] = true;
      }
    }
  }
  return ret;
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