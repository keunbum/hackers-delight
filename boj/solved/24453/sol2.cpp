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
  int n, m;
  cin >> n >> m;
  vector<int> a(m + 2);
  a[0] = 0;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  a[m + 1] = n + 1;
  sort(a.begin(), a.end());
  int x, y;
  cin >> x >> y;
  int L = 0;
  int R = 0;
  int add = -1;
  int mn = m;
  while (L < m + 1 - y) {
    while (R < m + 1 && (R - L - 1 < y || add < x)) {
      add += a[R + 1] - a[R];
      R += 1;
    }
    if (add >= x) {
      mn = min(mn, R - L - 1);
    }
    add -= a[L + 1] - a[L];
    L += 1;
  }
  cout << (m - mn) << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/