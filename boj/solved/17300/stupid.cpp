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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> stk(1, a[0]);
  array<bool, 10> was{};
  was[a[0]] = true;
  function<bool(void)> DFS = [&](void) -> bool {
    debug(stk);
    if (stk == a) {
      return true;
    }
    int i = (stk.back() - 1) / 3;
    int j = (stk.back() - 1) % 3;
    for (int di = -1; di <= 1; ++di) {
      for (int dj = -1; dj <= 1; ++dj) {
        if (di * di + dj * dj != 0) {
          for (int t = 1; t <= 2; ++t) {
            int ni = i + t * di;
            int nj = j + t * dj;
            if (ni < 0 || ni >= 3 || nj < 0 || nj >= 3) continue;
            int u = ni * 3 + nj + 1;
            if (!was[u]) {
              was[u] = true;
              stk.push_back(u);
              if (DFS()) return true;
              stk.pop_back();
              was[u] = false;
              break;
            }
          }
        }
      }
    }
    return false;
  };
  cout << (DFS() ? "YES" : "NO") << '\n';
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