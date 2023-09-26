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
  const int N = (int) 1e6;
  vector<bool> p(N + 1, true);
  for (int i = 2; i * i <= N; ++i) {
    if (p[i]) {
      for (int j = i * i; j <= N; j += i) {
        p[j] = false;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i <= N; ++i) {
    if (p[i]) {
      primes.push_back(i);
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int cnt = 0;
    for (int prime : primes) {
      int q = n - prime;
      if (q < prime) {
        break;
      }
      cnt += p[q];
    }
    cout << cnt << '\n';
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