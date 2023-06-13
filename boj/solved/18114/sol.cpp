#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

bitset<(int)1e8 + 1> was;
int a[(int)5e3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, C;
  cin >> N >> C;
  bool ok = false;
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
    ok |= (a[i] == C);
    was[a[i]] = 1;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      int v = C - (a[i] + a[j]);
      ok |= (v == 0 || (v > 0 && v != a[i] && v != a[j] && was[v]));
    }
  }
  cout << ok << '\n';
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