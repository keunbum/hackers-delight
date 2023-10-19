#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

long long solution(int r1, int r2) {
  long long ret = 0;
  for (long long x = 1; x <= r2; ++x) {
    auto Get = [&](long long r) {
      return sqrt(r * r - x * x);
    };
    int y1 = (x < r1 ? (int)(Get(r1) + ((int)Get(r1) != Get(r1))) : 0);
    int y2 = (int)Get(r2);
    ret += y2 - y1 + 1;
  }
  return 4 * ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto res = solution(2, 3);
  debug(res);
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