﻿#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif
int solution(vector<string> want, vector<int> number, vector<string> discount) {
  int ret = 0;
  map<string, int> mp;
  for (int i = 0; i < (int) discount.size(); i++) {
    if (i >= 10) {
      mp[discount[i - 10]] -= 1;
    }
    mp[discount[i]] += 1;
    bool ok = true;
    for (int j = 0; j < (int) want.size(); j++) {
      ok &= mp[want[j]] == number[j];
    }
    ret += ok;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/