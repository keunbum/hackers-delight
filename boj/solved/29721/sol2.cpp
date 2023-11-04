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
  int n, k;
  cin >> n >> k;
  set<pair<int, int>> s;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    s.emplace(x, y);
  }
  set<pair<int, int>> ns;
  for (auto[i, j] : s) {
    for (int dir = 0; dir < 4; ++dir) {
      const int di[] = {2, 0, -2, 0};
      const int dj[] = {0, 2, 0, -2};
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if (min(ni, nj) >= 0 && max(ni, nj) < n && s.count({ni, nj}) == 0) {
        ns.emplace(ni, nj);
      }
    }
  }
  cout << ns.size() << '\n';
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