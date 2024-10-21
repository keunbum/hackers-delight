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
  vector<array<int, 2>> a(n + m);
  for (int i = 0; i < n + m; ++i) {
    cin >> a[i][0];
    a[i][1] = i >= n;
  }
  sort(a.begin(), a.end(), [](auto& lhs, auto& rhs) { return lhs[0] < rhs[0]; });
  array<int64_t, 2> win{}, cur{}, cnt{};
  for (int i = 0; i < n + m; ++i) {
    if (i > 0 && a[i - 1][0] != a[i][0]) {
      for (int t = 0; t < 2; ++t) {
        cnt[t] += cur[t];
        cur[t] = 0;
      }
    }
    win[a[i][1]] += cnt[a[i][1] ^ 1];
    cur[a[i][1]] += 1;
  }
  cout << win[0] << " " << win[1] << " " << (int64_t(n) * m - (win[0] + win[1])) << '\n';
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