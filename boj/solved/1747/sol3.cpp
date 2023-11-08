#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

bool F(int n) {
  string s = to_string(n);
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

bool G(int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  for (cin >> n; ; ++n) {
    if (F(n) && G(n)) {
      cout << n << '\n';
      break;
    }
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