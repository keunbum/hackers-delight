#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

#define M 100000
#define N 200000

string a[M], b[M], strs[M + M];
int p[N], sz[N];

int Get(int x) {
  while (x != p[x]) {
    x = p[x] = p[p[x]];
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i];
      strs[i + i] = a[i];
      strs[i + i + 1] = b[i];
    }
    ranges::sort(strs, strs + 2 * m);
    int n = (int) (unique(strs, strs + 2 * m) - strs);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
      sz[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
      int x = (int) (lower_bound(strs, strs + n, a[i]) - strs);
      int y = (int) (lower_bound(strs, strs + n, b[i]) - strs);
      x = Get(x);
      y = Get(y);
      if (x != y) {
        sz[x] += sz[y];
        p[y] = x;
      }
      cout << sz[x] << '\n';
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