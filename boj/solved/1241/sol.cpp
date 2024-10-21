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
  const int N = (int) 1e6;
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(N + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]] += 1;
  }
  vector<bool> was(N + 1, false);
  vector<int> res(N + 1, -1);
  for (int i = 0; i < n; i++) {
    if (was[a[i]]) {
      continue;
    }
    was[a[i]] = true;
    for (int j = a[i]; j <= N; j += a[i]) {
      res[j] += cnt[a[i]];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[a[i]] << '\n';
  }
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