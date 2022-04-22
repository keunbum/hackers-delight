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
  int X, Y, D, T;
  cin >> X >> Y >> D >> T;
  int L2 = X * X + Y * Y;
  cout << fixed << setprecision(17);
  double L = sqrt(L2);
  if (D <= T) {
    cout << L << '\n';
    return 0;
  }
  if (L >= D) {
    int qx = (int) (L / D);
    double r = L - qx * D;
    cout << T * qx + min(r, (double) T) << '\n';
    return 0;
  }
  cout << min({L, (double) T + T, T + (D - L)}) << '\n';
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