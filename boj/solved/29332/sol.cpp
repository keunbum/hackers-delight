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
  const int inf = (int) 2e9;
  int minx = -inf;
  int maxx = inf;
  int miny = -inf;
  int maxy = inf;
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    char d;
    cin >> x >> y >> d;
    if (d == 'L') maxx = min(maxx, x - 1);
    if (d == 'R') minx = max(minx, x + 1);
    if (d == 'U') miny = max(miny, y + 1);
    if (d == 'D') maxy = min(maxy, y - 1);
  }
  for (int v : {minx, maxx, miny, maxy}) {
    if (abs(v) == inf) {
      cout << "Infinity" << '\n';
      return 0;
    }
  }
  cout << (1LL * (maxx - minx + 1) * (maxy - miny + 1)) << '\n';
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