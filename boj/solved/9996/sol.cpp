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
  string t;
  cin >> t;
  int nt = int(t.size());
  while (n--) {
    string s;
    cin >> s;
    int ns = int(s.size());
    bool ok = ns >= nt - 1;
    {
      int i = 0;
      while (i < ns && t[i] == s[i]) {
        i += 1;
      }
      ok &= t[i] == '*';
    }
    {
      int i = nt - 1;
      int j = ns - 1;
      while (j >= 0 && t[i] == s[j]) {
        i -= 1;
        j -= 1;
      }
      ok &= t[i] == '*';
    }
    cout << (ok ? "DA" : "NE") << '\n';
  }
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