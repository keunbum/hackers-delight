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
  int n, W;
  cin >> n >> W;
  vector<int> a, b;
  int wsum = 0;
  long long ssum = 0;
  for (int i = 0; i < n; ++i) {
    int t, s;
    cin >> t >> s;
    if (t == 3) {
      a.push_back(s);
      wsum += 3;
      ssum += s;
    } else {
      b.push_back(s);
    }
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  int L = (int) a.size() - 1;
  while (L >= 0 && wsum > W) {
    wsum -= 3;
    ssum -= a[L];
    L -= 1;
  }
  int R = -1;
  long long ans = 0;
  while (true) {
    while (R + 1 < (int) b.size() && wsum + 5 <= W) {
      wsum += 5;
      ssum += b[R + 1];
      R += 1;
    }
    ans = max(ans, ssum);
    if (L == -1) {
      break;
    }
    wsum -= 3;
    ssum -= a[L];
    L -= 1;
  }
  cout << ans << '\n';
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