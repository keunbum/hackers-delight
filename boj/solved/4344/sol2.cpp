#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    int cnt = 0;
    for (int x : a) {
      cnt += (x * n > sum);
    }
    double avr = 1.0 * cnt / n;
    int res = (int) ((avr + 5e-6) * 1e5);
    cout << res / 1000 << '.' << setfill('0') << setw(3) << res % 1000 << '%' << '\n'; 
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