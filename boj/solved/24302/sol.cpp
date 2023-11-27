#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int A(int x) {
  x /= 1000;
  if (x <= 5) return 400;
  if (x <= 10) return 700;
  if (x <= 20) return 1200;
  if (x <= 30) return 1700;
  return x * 57;
}

int B(int x) {
  x /= 1000;
  if (x <= 2) return 90 + 90 * x;
  if (x <= 5) return 100 + 85 * x;
  if (x <= 20) return 125 + 80 * x;
  if (x <= 40) return 325 + 70 * x;
  return 925 + 55 * x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  cout << fixed << setprecision(2) << ((min(A(x), B(x)) + min(A(y), B(y))) / 100.0) << '\n';
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