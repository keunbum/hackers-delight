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
  double T;
  int n;
  cin >> T >> n;
  int sum = 0;
  int mx = 0;
  int mn = (int) 1e6;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }
  debug(mn, mx, sum);
  auto Calc = [&](double L, double R) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
      debug(i, a[i], ceil(a[i] / R), (int) ceil(a[i] / R));
      ret += (int) ceil(a[i] / R);
    }
    return ret;
  };
  int ans = 500;
  {
    double low = 0;
    double high = mn * 0.5;
    for (int i = 0; i < 100; i++) {
      double midL = 0.5 * (low + high);
      double midR = midL / T;
      if (midL + midR > sum || midR > mx) {
        high = midL;
      } else {
        low = midL;
      }
    }
    double L = low;
    double R = L / T;
    int res1 = Calc(L, R);
    debug(L, R, L / R, res1);
    ans = min(ans, res1);
  }
  {
    double L = mn;
    double R = L / T;
    int res2 = Calc(L, R);
    debug(L, R, L / R, res2);
    if (!(R > mx || (R < mx && mx - R < L))) {
      ans = min(ans, res2);
    }
  }
  assert(ans < 500);
  cout << ans << '\n';
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
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/