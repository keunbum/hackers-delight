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
  using ull = unsigned long long;
  vector<ull> a;
  vector<pair<int, int>> b;
  for (int y = 0; y < 63; ++y) {
    for (int x = 0; x <= y; ++x) {
      a.push_back((1ULL << y) + (1ULL << x));
      b.emplace_back(x, y);
    }
  }
  int n;
  cin >> n;
  while (n--) {
    ull m;
    cin >> m;
    int i = (int) (upper_bound(a.begin(), a.end(), m) - a.begin()) - 1;
    if (i == -1 || a[i + 1] - m < m - a[i]) {
      i += 1;
    }
    cout << b[i].first << ' ' << b[i].second << '\n';
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