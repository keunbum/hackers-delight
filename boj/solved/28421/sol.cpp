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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  bool zero = false;
  while (q--) {
    int c;
    cin >> c;
    if (c == 1) {
      int x;
      cin >> x;
      if (x == 0) {
        cout << (zero && n > 1) << '\n';
        continue;
      }
      bool found = false;
      set<int> s;
      for (int i = 0; i < n; ++i) {
        if (s.find(a[i]) != s.end()) {
          found = true;
          break;
        }
        if (a[i] != 0 && x % a[i] == 0) {
          s.insert(x / a[i]);
        }
      }
      cout << found << '\n';
    } else {
      int i;
      cin >> i;
      a[--i] = 0;
      zero = true;
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