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
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<int> ret;
  for (int i = 1; i < n; ++i) {
    bool ok = true;
    int k = x[i] - x[0];
    for (int j = 1; j < n; ++j) {
      if (binary_search(x.begin(), x.end(), x[j] + k) || binary_search(x.begin(), x.end(), x[j] - k)) {
        continue;
      }
      ok = false;
      break;
    }
    if (ok) {
      ret.push_back(k);
    }      
  }
  cout << ret.size() << '\n';
  for (int x : ret) cout << x << " ";
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