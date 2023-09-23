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
  int n, k;
  cin >> n >> k;
  auto Add = [&](int i, int by) {
    i += by;
    if (i >= 2 * n) i -= 2 * n;
    if (i < 0) i += 2 * n;
    return i;
  };
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }
  int rep = 1;
  int beg = 0;
  vector<bool> b(2 * n , false);
  while (true) {
    beg = Add(beg, -1);
    int end = Add(beg, n - 1);
    b[end] = false;
    for (int i = Add(end, -1); i != beg; i = Add(i, -1)) {
      int j = Add(i, +1);
      if (b[i] && !b[j] && a[j] > 0) {
        b[i] = false;
        k -= (--a[j] == 0);
        if (j != end) {
          b[j] = true;
        }
      }
    }
    if (a[beg] > 0) {
      b[beg] = true;
      k -= (--a[beg] == 0);
    }
    if (k <= 0) {
      break;
    }
    rep += 1;
  }
  cout << rep << '\n';
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