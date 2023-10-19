#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

long long solution(int r1, int r2) {
  auto Solve = [&](long long r) {
    long long in = 0;
    long long bound = 0;
    for (long long x = 0; x <= r; ++x) {
      int y = (int) sqrt(r * r - x * x);
      long long add1, add2;
      if (1LL * y * y + 1LL * x * x == 1LL * r * r) {
        add1 = 2 * y - 1;
        add2 = 2 - (x == r);
      } else {
        add1 = 2 * y + 1;
        add2 = 0;
      }
      if (x > 0) {
        add1 *= 2;
        add2 *= 2;
      }
      in += add1;
      bound += add2;
    }
    return make_pair(in, bound);
  };
  auto[in1, bound1] = Solve(r1);
  auto[in2, bound2] = Solve(r2);
  return in2 + bound2 - in1; 
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