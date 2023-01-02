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
  int n, l, r, x;
  cin >> n >> l >> r >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int bits = 0; bits < (1 << n); bits++) {
    int sum = 0;
    int mx = 0;
    int mn = (int) 1e7;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if ((bits >> i) & 1) {
        sum += a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        cnt += 1;
      }
    }
    if (cnt >= 2 && l <= sum && sum <= r && mx - mn >= x) {
      ans += 1;
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
  * deep breathing. keep calm
  
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