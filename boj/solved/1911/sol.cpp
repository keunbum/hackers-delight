﻿#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, L;
  cin >> n >> L;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    int s, e;
    cin >> s >> e;
    a[i] = {s, e};
  }
  sort(a.begin(), a.end());
  int pre = -1;
  int ans = 0;
  for (auto&[s, e] : a) {
    int st = max(s, pre);
    int len = max(0, e - st);
    ans += (len + L - 1) / L;
    int r = len % L;
    if (r != 0) {
      pre = e - r + L;
    } else {
      pre = max(pre, e);
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