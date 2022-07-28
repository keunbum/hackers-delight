#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int Read() {
  int a, b, c;
  scanf("%d:%d:%d", &a, &b, &c);
  return a * 3600 + b * 60 + c;
}

int main() {
  const int md = 24 * 3600;
  int st = Read();
  int en = Read();
  int ans = (en - st + md) % md;
  int x = ans / 3600;
  int y = (ans % 3600) / 60;
  int z = ans % 60;
  if (x + y + z == 0) {
    x = 24;
  }
  printf("%02d:%02d:%02d\n", x, y, z);
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