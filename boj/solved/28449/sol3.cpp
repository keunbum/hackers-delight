#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<int, array<int, 2>> mp;
  for (int i = 0; i < n + m; ++i) {
    int x;
    cin >> x;
    mp[x][i >= n] += 1;
  }
  int s0 = 0;
  int s1 = 0;
  int64_t x = 0, y = 0, z = 0;
  for (auto& [_, cnt] : mp) {
    x += 1LL * cnt[0] * s1;
    y += 1LL * cnt[1] * s0;
    z += 1LL * cnt[0] * cnt[1];
    s0 += cnt[0];
    s1 += cnt[1];
  }
  cout << x << " " << y << " " << z << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * Do I have to solve like this?
  
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