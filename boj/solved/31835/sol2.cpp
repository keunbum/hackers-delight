#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

bool Encode(char v) {
  return v == 'T';
}

bool Calc(bool v, char op, bool u) {
  if (op == '&') return v && u;
  if (op == '|') return v || u;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<char> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  char C;
  cin >> C;
  if (n == 1) {
    cout << (a[0] != C) << '\n';
    return 0;
  }
  bool cur = Encode(a[0]);
  for (int i = 2; i < n - 2; i += 2) {
    cur = Calc(cur, a[i - 1], Encode(a[i]));
  }
  int ans = 3;
  for (char op : string("&|")) {
    for (char v : string("FT")) {
      if (Calc(cur, op, Encode(v)) == Encode(C)) {
        ans = min(ans, int(op != a[n - 2]) + int(v != a[n - 1]));
      }
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
  * Do I have to solve like this?
  
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
