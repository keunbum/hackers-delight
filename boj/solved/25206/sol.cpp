﻿#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

double Get(string s) {
  return 4 - (s[0] - (s[0] == 'F') - 'A') + (s.size() > 1 && s[1] == '+') * 0.5;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  double allsum = 0;
  double ssum = 0;
  int qq = 20;
  while (qq--) {
    string _, g;
    double s;
    cin >> _ >> s >> g;
    if (g != "P") {
      ssum += s;
      allsum += s * Get(g);
    }
  }
  cout << fixed << setprecision(17) << (allsum / ssum) << '\n';
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