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
  int n, k;
  cin >> n >> k;
  vector<array<int, 2>> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i][0];
  }
  int rep = 1;
  while (true) {
    rotate(a.begin(), prev(a.end()), a.end());
    a[n - 1][1] = 0;
    for (int i = n - 2; i >= 0; --i) {
      if (a[i][1] && !a[i + 1][1] && a[i + 1][0] > 0) {
        a[i][1] = 0;
        k -= (--a[i + 1][0] == 0);
        if (i + 1 != n - 1) {
          a[i + 1][1] = 1;
        }
      }
    }
    if (a[0][0] > 0) {
      a[0][1] = 1;
      k -= (--a[0][0] == 0);
    }
    if (k <= 0) {
      break;
    }
    rep += 1;
  }
  cout << rep << '\n';
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