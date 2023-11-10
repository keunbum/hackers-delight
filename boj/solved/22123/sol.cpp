#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int Encode(string& s) {
  array<int, 3> a;
  for (int i = 0; i < 3; ++i) a[i] = 10 * (s[3 * i] - '0') + (s[3 * i + 1] - '0');
  return a[0] * 3600 + a[1] * 60 + a[2];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string a, b;
    int k;
    cin >> a >> b >> k;
    k *= 60;
    int t = Encode(b) - Encode(a);
    if (t <= 0) t += 24 * 3600;
    cout << (k <= t ? "Perfect" : (k <= t + 3600 ? "Test" : "Fail")) << '\n';
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