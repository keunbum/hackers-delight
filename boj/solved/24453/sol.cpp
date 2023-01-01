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
  vector<int> b(m + 1);
  for (int i = 0; i < m + 1; i++) {
    b[i] = a[i + 1] - a[i] - 1;
  }
  vector<long long> sum(m + 2);
  sum[0] = 0;
  for (int i = 0; i < m + 1; i++) {
    sum[i + 1] = sum[i] + b[i];
  }
  debug(a, b, sum);
  int x, y;
  cin >> x >> y;
  int low = y;
  int high = m;
  debug(low, high);
  while (low < high) {
    int mid = (low + high) / 2;
    long long mx = 0;
    for (int i = mid; i < m + 1; i++) {
      mx = max(mx, sum[i + 1] - sum[i - mid]);
    }
    debug(low, mid, high, mx, mx + mid);
    if (mx + mid >= x) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << (m - low) << '\n';
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