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
  tuple<int, int, int, int> need;
  cin >> get<0>(need) >> get<1>(need) >> get<2>(need) >> get<3>(need);
  vector<tuple<int, int, int, int>> pref(n + 1);
  pref[0] = {0, 0, 0, 0};
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i];
    if (mp[s[i]] == 0) get<0>(pref[i + 1]) += 1; else
    if (mp[s[i]] == 1) get<1>(pref[i + 1]) += 1; else
    if (mp[s[i]] == 2) get<2>(pref[i + 1]) += 1;
    else get<3>(pref[i + 1]) += 1;
  }
  int ans = 0;
  for (int i = p; i <= n; ++i) {
    bool ok = true;
    ok &= (get<0>(pref[i]) - get<0>(pref[i - p])) >= get<0>(need);
    ok &= (get<1>(pref[i]) - get<1>(pref[i - p])) >= get<1>(need);
    ok &= (get<2>(pref[i]) - get<2>(pref[i - p])) >= get<2>(need);
    ok &= (get<3>(pref[i]) - get<3>(pref[i - p])) >= get<3>(need);
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