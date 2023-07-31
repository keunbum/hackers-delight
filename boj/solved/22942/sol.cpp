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
  int n;
  cin >> n;
  vector<tuple<int, int, int>> a(n + n);
  for (int i = 0; i < n; ++i) {
    int x, r;
    cin >> x >> r;
    a[i] = {x - r, ~1, i};
    a[i + n] = {x + r, ~-1, i};
  }
  sort(a.begin(), a.end());
  vector<int> stk;
  for (auto[_, t, i] : a) {
    t = ~t;
    if (t > 0) {
      stk.push_back(i);
    } else {
      if (stk.empty() || stk.back() != i) {
        cout << "NO" << '\n';
        return 0;
      }
      stk.pop_back();
    }
  }
  cout << "YES" << '\n';
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