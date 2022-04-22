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
  int xa, ya, xb, yb, xc, yc, xd, yd;
  cin >> xa >> ya >> xb >> yb;
  cin >> xc >> yc >> xd >> yd;
  if (xa > xc) {
    swap(xa, xc);
    swap(ya, yc);
    swap(xb, xd);
    swap(yb, yd);
  }
  if (xb < xc || ya > yd || yb < yc) {
    cout << "NULL" << '\n';
    return 0;
  }
  if (xb == xc && (ya == yd || yb == yc)) {
    cout << "POINT" << '\n';
    return 0;
  }
  if (xb == xc || ya == yd || yb == yc) {
    cout << "LINE" << '\n';
    return 0;
  }
  cout << "FACE" << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
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