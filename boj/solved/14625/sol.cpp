#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int Encode(int h, int m) { return h * 60 + m; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int sh, sm, eh, em, n;
  cin >> sh >> sm >> eh >> em >> n;
  int st = Encode(sh, sm);
  int et = Encode(eh, em);
  int ans = 0;
  for (int h = 0; h < 24; ++h) {
    for (int m = 0; m < 60; ++m) {
      int c = Encode(h, m);
      if (st <= c && c <= et) {
        ans += h % 10 == n || h / 10 == n || m % 10 == n || m / 10 == n;
      }
    }
  }
  cout << ans << '\n'; 
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