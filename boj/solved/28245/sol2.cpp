#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    long long m;
    cin >> m;
    int i = -1, j = -1;
    for (int p = 63; p >= 0; --p) {
      if ((m >> p) & 1) {
        if (i == -1) i = p; else
        if (j == -1) j = p;
      }
    }
    assert(i != -1);
    if (j == -1) {
      i -= (i > 0);
      cout << i << ' ' << i << '\n';
    } else {
      if (((1LL << i) + (1LL << (j + 1))) - m < m - ((1LL << i) + (1LL << j)))
        j += 1;
      cout << j << ' ' << i << '\n';
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