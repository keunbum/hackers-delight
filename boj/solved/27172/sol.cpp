#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = (int) 1e6;
  vector<bool> be(N + 1, false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    be[a[i]] = true;
  }
  vector<int> scores(N + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = a[i] << 1; j <= N; j += a[i]) {
      scores[j] -= be[j];
      scores[a[i]] += be[j];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << scores[a[i]] << " \n"[i == n - 1];
  }
  debug(1.0 * clock() / CLOCKS_PER_SEC);
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
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