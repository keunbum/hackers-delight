#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

struct St {
  int x, y;
  bool operator<(const St& o) const {
    return x * o.y < y * o.x;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  St a[3];
  for (int i = 0; i < 3; ++i) {
    int x, y;
    cin >> x >> y;
    a[i] = {y * 10, 10 * x >= 5000 ? 10 * x - 500 : 10 * x};
  }
  int i = (int) (max_element(a, a + 3) - a);
  cout << "SNU"[i] << '\n';
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