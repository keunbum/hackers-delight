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
  int N, m;
  cin >> N >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  vector<int> perm(m);
  iota(perm.begin(), perm.end(), 0);
  sort(perm.begin(), perm.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  int L = 0;
  int R = -1;
  int s = 0;
  while (L < m) {
    while (R + 1 < m && s < N) {
      s += a[perm[R + 1]];
      R += 1;
    }
    debug(L, R, s);
    if (s <= 2 * N) {
      cout << R - L + 1 << '\n';
      for (int i = L; i <= R; ++i) {
        cout << perm[i] + 1 << '\n';
      }
      return 0;
    }
    s -= a[perm[L]];
    L += 1;
  }
  assert(false);
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