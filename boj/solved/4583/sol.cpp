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
  int mp[128];
  iota(mp + 'a', mp + 'z' + 1, 'a');
  mp['b'] = 'd';
  mp['d'] = 'b';
  mp['p'] = 'q';
  mp['q'] = 'p';
  while (true) {
    string s;
    cin >> s;
    if (s == "#") break;
    bool ok = true;
    for (char& ch : s) {
      if (strchr("bdpqiovwx", ch) == nullptr) {
        ok = false;
        break;
      }
      ch = mp[(int)ch];
    }
    reverse(s.begin(), s.end());
    cout << (ok ? s : "INVALID") << '\n';
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