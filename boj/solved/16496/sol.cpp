#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

inline int Len(int x) {
  int ret = (x == 0);
  while (x > 0) {
    ret += 1;
    x /= 10;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  __int128 p10[11];
  p10[0] = 1;
  for (int i = 1; i < 11; ++i) p10[i] = p10[i - 1] * 10;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end(), [&](int x, int y) {
    return p10[Len(y)] * x + y > p10[Len(x)] * y + x;
  });
  string ans;
  for (int x : a) ans += to_string(x);
  cout << (ans[0] == '0' ? "0" : ans) << '\n';
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