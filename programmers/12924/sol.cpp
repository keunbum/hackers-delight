#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int n) {
  int ret = 0;
  for (int k = 1; k <= n; k++) {
    if (2 * n % k == 0) {
      int t = 2 * n / k;
      int p = t - k + 1;
      if (p > 0 && p % 2 == 0) {
        ret += 1;
      }
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i <= 20; i++) {
    debug(i, solution(i));
  }
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