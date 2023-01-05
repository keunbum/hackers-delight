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
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    vector<pair<int, int>> ps(n);
    for (int i = 0; i < n; i++) {
      int s, e;
      cin >> s >> e;
      s <<= 1;
      e <<= 1;
      ps[i] = {e, s};
    }
    int ans = 0;
    sort(ps.begin(), ps.end());
    vector<bool> used(48, false);
    for (auto[e, s] : ps) {
      for (int i = s; i < e; i++) {
        if (!used[i]) {
          used[i] = true;
          ans += 1;
          break;
        }
      }
    }
    static int qq = 1;
    cout << "On day " << qq << " Emma can attend as many as " << ans << " parties." << '\n';
    qq += 1;
  }
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
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/