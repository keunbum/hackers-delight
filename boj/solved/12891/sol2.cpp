#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  array<int, 128> mp;
  mp['A'] = 0;
  mp['C'] = 1;
  mp['G'] = 2;
  mp['T'] = 3;
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  valarray<int> need(4);
  for (int i = 0; i < 4; ++i) cin >> need[i];
  vector<valarray<int>> pref(n + 1, valarray<int>(0, 4));
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i];
    pref[i + 1][mp[s[i]]] += 1;
  }
  int ans = 0;
  for (int i = p; i <= n; ++i) {
    valarray<int> cur = pref[i] - pref[i - p];
    bool ok = true;
    for (int j = 0; j < 4; ++j) ok &= cur[j] >= need[j];
    ans += ok;
  }
  cout << ans  << '\n';
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