#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  /*for (double _x = 1; _x <= 100000; ++_x) {
    double x = _x;
    int k = 0;
    bool ok = true;
    while (x > 0) {
      x -= (x + 1) * 0.5;
      if (x < 0) {
        ok = false;
        break;
      }
      k += 1;
    }
    if (ok) {
      debug(_x, k);
    }
  }*/
  int tt;
  cin >> tt;
  while (tt--) {
    int k;
    cin >> k;
    cout << (1 << k) - 1 << '\n';
  }
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