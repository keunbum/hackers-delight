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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<bool> good(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    good[i] = (a[i] & k) == a[i];
  }
  int beg = 0;
  while (beg < n) {
    if (good[beg] && (beg == 0 || !good[beg - 1])) {
      int cur = 0;
      int end = beg;
      while (end < n && good[end]) {
        cur |= a[end++];
      }
      if (cur == k) {
        cout << beg + 1 << " " << end << '\n';
        return 0;
      }
      beg = end;
      continue;
    }
    beg += 1;
  }
  cout << -1 << '\n';
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