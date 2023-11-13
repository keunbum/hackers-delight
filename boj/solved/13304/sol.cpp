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
  vector<array<int, 2>> a(7);
  while (n--) {
    int s, y;
    cin >> s >> y;
    a[y][s] += 1;
  }
  int ans = 0;
  for (int sum : {
    a[1][0] + a[1][1] + a[2][0] + a[2][1],
    a[3][0] + a[4][0], a[3][1] + a[4][1],
    a[5][0] + a[6][0], a[5][1] + a[6][1]
  }) {
    ans += (sum + k - 1) / k;
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