#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

const int N = (int) 2.5e5;

int a[N], b[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, W;
  cin >> N >> W;
  int n = 0;
  int m = 0;
  int w = 0;
  long long sum = 0LL;
  for (int _ = 0; _ < N; ++_) {
    int t, s;
    cin >> t >> s;
    if (t == 3) {
      w += 3;
      sum += s;
      a[n++] = s;
    } else {
      b[m++] = s;
    }
  }
  sort(a, a + n, greater<int>());
  sort(b, b + m, greater<int>());
  int L = n - 1;
  while (L >= 0 && w > W) {
    w -= 3;
    sum -= a[L];
    L -= 1;
  }
  int R = -1;
  long long ans = 0;
  while (true) {
    while (R + 1 < m && w + 5 <= W) {
      w += 5;
      sum += b[R + 1];
      R += 1;
    }
    ans = max(ans, sum);
    if (L == -1) {
      break;
    }
    w -= 3;
    sum -= a[L];
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