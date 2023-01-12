﻿#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> k >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int h, s;
    cin >> h >> s;
    a[i] = {s, h};
  }
  sort(a.rbegin(), a.rend());
  vector<bool> dp(k + 1, false);
  dp[0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = k; j - a[i].second >= 0; j--) {
      dp[j] = dp[j] | dp[j - a[i].second];
    }
    if (dp[k]) {
      cout << a[i].first << '\n';
      return 0;
    }
  }
  assert(false);
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
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/