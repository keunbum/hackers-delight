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
  int T;
  cin >> T;
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  vector<int> b(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  vector<int> sumA;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = i; j <= n; j++) {
      sum += a[j];
      sumA.push_back(sum);
    }
  }
  vector<int> sumB;
  for (int i = 1; i <= m; i++) {
    int sum = 0;
    for (int j = i; j <= m; j++) {
      sum += b[j];
      sumB.push_back(sum);
    }
  }
  debug(sumA.size());
  debug(sumB.size());
  sort(sumA.begin(), sumA.end());
  sort(sumB.begin(), sumB.end());
  long long ans = 0;
  for (int x : sumA) {
    int y = T - x;
    auto it = lower_bound(sumB.begin(), sumB.end(), y);
    auto jt = upper_bound(sumB.begin(), sumB.end(), y);
    int cnt = (int) (jt - it);
    ans += cnt;
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
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
  * 0-based or 1-based?
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/