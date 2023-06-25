#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

const int MAXPUSH = (int) 1e6;

int due[(MAXPUSH << 1) + 5];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  int b = MAXPUSH, e = MAXPUSH + 1;
  while (q--) {
    int c;
    cin >> c;
    if (c <= 2) {
      int x;
      cin >> x;
      (c & 1 ? due[b--] : due[e++]) = x;
    } else
    if (c <= 4) cout << (e - b == 1 ? -1 : (c & 1 ? due[++b] : due[--e])) << '\n'; else
    if (c == 5) cout << (e - b - 1) << '\n'; else
    if (c == 6) cout << (e - b == 1) << '\n'; else
    if (c <= 8) cout << (e - b == 1 ? -1 : (c & 1 ? due[b + 1] : due[e - 1])) << '\n';
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