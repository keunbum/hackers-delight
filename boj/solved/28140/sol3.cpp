#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int N = (int) 1e6;

char s[N + 1];
int lpos[N + 2];
int rpos[N + 2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  cin >> s;
  int ln = 0;
  int rn = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      lpos[ln++] = i;
    }
    if (s[n - 1 - i] == 'B') {
      rpos[rn++] = ~(n - 1 - i);
    }
  }
  lpos[ln] = lpos[ln + 1] = n + 1;
  rpos[rn] = rpos[rn + 1] = ~(-1);
  while (q--) {
    int l, r;
    cin >> l >> r;
    int i = (int) (lower_bound(lpos, lpos + ln, l) - lpos);
    int j = (int) (lower_bound(rpos, rpos + rn, ~r) - rpos);
    if (lpos[i + 1] < ~rpos[j + 1]) {
      cout << lpos[i] << ' ' << lpos[i + 1] << ' ' << ~rpos[j + 1] << ' ' << ~rpos[j] << '\n';
    } else {
      cout << -1 << '\n';
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
  * think rationally. keep calm
  
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