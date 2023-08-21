#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<int> Get(int x) {
  vector<int> ret{x};
  array<bool, 1000> was{};
  while (true) {
    int y = 0;
    while (x > 0) {
      y += (x % 10) * (x % 10);
      x /= 10;
    }
    if (was[y]) {
      break;
    }
    was[y] = true;
    ret.push_back(y);
    x = y;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int a, b;
    cin >> a >> b;
    if (a + b == 0) {
      break;
    }
    cout << a << ' ' << b << ' ';
    auto x = Get(a);
    auto y = Get(b);
    array<int, 2> best{-1, -1};
    for (int i = 0; i < (int) x.size(); ++i) {
      for (int j = 0; j < (int) y.size(); ++j) {
        if (x[i] == y[j] && (best[0] == -1 || i + j < best[0] + best[1])) {
          best = {i, j};
        }
      }
    }
    cout << (best[0] + best[1] + 2) << '\n';
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