#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int F(int a, int b, char op) {
  int ret = -1;
  if (op == '+') ret = a + b;
  if (op == '-') ret = a - b;
  if (op == '*') ret = a * b;
  if (op == '/') ret = a / b;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  char op0, op1;
  cin >> a >> op0 >> b >> op1 >> c;
  array<int, 2> v{F(F(a, b, op0), c, op1), F(a, F(b, c, op1), op0)};
  sort(v.begin(), v.end());
  cout << v[0] << "\n" << v[1] << '\n';
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