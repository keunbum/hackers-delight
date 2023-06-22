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
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
    if (i > 0) {
      ans += abs(a[i] - a[i - 1]);
    }
  }
  auto[amin_iter, amax_iter] = minmax_element(a.begin(), a.end());
  int amn = *amin_iter;
  int amx = *amax_iter;
  n -= k;
  if (n == 0) {
    cout << ans << '\n';
    return 0;
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  auto[bmin_iter, bmax_iter] = minmax_element(b.begin(), b.end());
  int bmn = *bmin_iter;
  int bmx = *bmax_iter;
  if (bmn < amn) {
    ans += min(min(a[0], a[k - 1]) - bmn, 2 * (amn - bmn));
  }
  if (amx < bmx) {
    ans += min(bmx - max(a[0], a[k - 1]), 2 * (bmx - amx));
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