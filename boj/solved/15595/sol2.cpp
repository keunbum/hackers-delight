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
  int x = 0;
  int y = 0;
  set<string> is_ok;
  map<string, int> submit;
  int tt;
  cin >> tt;
  while (tt--) {
    int _, type;
    string s;
    cin >> _ >> s >> type >> _ >> _ >> _ >> _;
    submit[s] += 1;
    if (s != "megalusion" && type == 4 && is_ok.find(s) == is_ok.end()) {
      is_ok.insert(s);
      x += 1;
      y += submit[s];
    }
  }
  cout << fixed << setprecision(17) << (y == 0 ? 0 : (100.0 * x / y)) << '\n';
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