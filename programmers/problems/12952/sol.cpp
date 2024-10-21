#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int n) {
  vector<bool> col(n, false);
  vector<bool> diag1(n + n - 1, false);
  vector<bool> diag2(n + n - 1, false);
  int ret = 0;
  function<void(int)> Dfs = [&](int i) {
    debug(i, col, diag1, diag2);
    if (i == n) {
      ret += 1;
      return;
    }
    for (int j = 0; j < n; j++) {
      if (!col[j] && !diag1[i - j + n - 1] && !diag2[i + j]) {
        col[j] = diag1[i - j + n - 1] = diag2[i + j] = true;
        Dfs(i + 1);
        col[j] = diag1[i - j + n - 1] = diag2[i + j] = false;
      }
    }
  };
  Dfs(0);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution(4);
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