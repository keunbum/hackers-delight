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
  const int MAX = (int) 3e4 + 1;
  int x;
  cin >> x;
  vector<int> res;
  for (int y = 0; y <= x; y++) {
    vector<int> cur{x, y};
    cur.reserve(MAX);
    while (cur.back() >= 0) {
      int sz = (int) cur.size();
      cur.push_back(cur[sz - 2] - cur[sz - 1]);
    }
    cur.pop_back();
    if (cur.size() > res.size()) {
      swap(res, cur);
    }
  }
  int sz = res.size();
  cout << sz << '\n';
  for (int i = 0; i < sz; i++) {
    cout << res[i] << " \n"[i == sz - 1];
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