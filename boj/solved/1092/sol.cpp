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
  int n;
  cin >> n;
  vector<int> a(n);
  int max_a = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    max_a = max(max_a, a[i]);
  }
  sort(a.begin(), a.end());
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    if (b[i] > max_a) {
      cout << -1 << '\n';
      return 0;
    }
  }
  sort(b.begin(), b.end());
  int low = 1, high = m;
  while (low < high) {
    int mid = (low + high) >> 1;
    bool ok = true;
    vector<int> cnt(n, 0);
    int i = 0;
    for (int j = 0; j < m; ++j) {
      while (i < n && (b[j] > a[i] || cnt[i] == mid)) {
        i += 1;
      }
      if (i == n) {
        ok = false;
        break;
      } 
      cnt[i] += 1;
    }
    if (ok) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
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