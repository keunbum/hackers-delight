#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> cmd(n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> cmd[i] >> v[i];
  }
  int ans = 0;
  for (int x = 1; x <= 100; ++x) {
    bool ok = true;
    int y = x;
    for (int i = 0; i < n; ++i) {
      if (cmd[i] == "ADD") y += v[i];
      if (cmd[i] == "SUBTRACT") {
        y -= v[i];
        if (y < 0) {
          ok = false;
          break;
        }
      }
      if (cmd[i] == "MULTIPLY") y *= v[i];
      if (cmd[i] == "DIVIDE") {
        if (y % v[i] != 0) {
          ok = false;
          break;
        }
        y /= v[i];
      }
    }
    ans += !ok;
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