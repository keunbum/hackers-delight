#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

double GetH(double a, double b) {
  return sqrt(a * a - b * b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const double eps = 1e-4;
  double x, y, c;
  cin >> x >> y >> c;
  double low = 0;
  double high = min(x, y);
  while (low + eps < high) {
    double mid = (low + high) / 2;
    double hx = GetH(x, mid);
    double hy = GetH(y, mid);
    double d = hx * hy / (hx + hy);
    if (d < c) {
      high = mid;
    } else {
      low = mid;
    }
  }
  cout << fixed << setprecision(3) << low << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/