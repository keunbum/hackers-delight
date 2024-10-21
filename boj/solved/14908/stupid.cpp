﻿#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> t(n), s(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> s[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  vector<int> best;
  long long mn = (long long)9e18;
  do {
    int acc = 0;
    long long res = 0;
    for (int i : order) {
      res += 1LL * acc * s[i];
      acc += t[i];
    }
    if (mn > res) {
      mn = res;
      best = order;
    }
  } while (next_permutation(order.begin(), order.end()));
  for (int i : best) {
    cout << i + 1 << ' ';
  }
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