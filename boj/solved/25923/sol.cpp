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
  const int MAXL = 20;
  array<int, MAXL> p2;
  {
    p2[0] = 1;
    for (int i = 1; i < MAXL; i++) {
      p2[i] = p2[i - 1] * 2;
    }
  }
  int n, k;
  cin >> n >> k;
  {
    int m = (int) (upper_bound(p2.begin(), p2.end(), n) - p2.begin()) - 1;
    if (k < 4 || n == p2[m] || n == p2[m] + 1) {
      cout << -1 << '\n';
      return 0;
    }
    int ex_dist = 2 * (n - 1 + m);
    cout << ex_dist << '\n';
  }
  vector<int> res;
  vector<bool> used(n + 1, false);
  used[1] = true;
  for (int rot = 0; rot < 2; rot++) {
    static const int sts[] = {3, 5};
    vector<int> path(1, 1);
    int v = sts[rot];
    while (v <= n) {
      used[v] = true;
      path.push_back(v);
      int i = (int) (upper_bound(p2.begin(), p2.end(), v) - p2.begin()) - 1;
      bool found = false;
      if (v % 2 == 0) {
        for (int d = 2; d <= 4; d += 2) {
          int nv = v + d;
          if (used[nv] || (nv & v) == 0) {
            continue;
          }
          v += d;
          found = true;
          break;
        }
        if (!found) {
          v += 3;
        }
      } else
      if (v == p2[i] + 1) {
        v = v - 1;
      } else {
        v += 2;
      }
    }
    if (rot == 1) {
      if (res.back() != n && path.back() != n) {
        used[n] = true;
        path.push_back(n);
      }
      reverse(path.begin(), path.end());
    }
    for (int v : path) {
      res.push_back(v);
    }
  }
  assert((int) res.size() == n + 1);
  for (int i = 0; i < n + 1; i++) {
    cout << res[i] << " \n"[i == n];
  }
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