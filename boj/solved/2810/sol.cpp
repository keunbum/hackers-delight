#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> can(n + 1, false);
  bool is_first = true;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S') {
      can[i] = true;
      can[i + 1] = true;
    } else
    if (is_first) {
      can[i] = true;
      is_first = false;
    } else {
      can[i + 1] = true;
      is_first = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (can[i]) {
      can[i] = false;
      ans += 1;
    } else
    if (can[i + 1]) {
      can[i + 1] = false;
      ans += 1;
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
  * keep calm
  
 * stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/