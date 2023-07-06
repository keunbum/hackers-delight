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
  map<string, int> mp;
  int n, m;
  cin >> n >> m;
  while (n--) {
    string s;
    cin >> s;
    if ((int) s.size() >= m) {
      mp[s] += 1;
    }
  }
  vector<string> a;
  vector<int> b;
  for (auto&[s, v] : mp) {
    a.push_back(s);
    b.push_back(v);
  }
  vector<int> order(a.size());
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    size_t x = a[i].size(), y = a[j].size();
    return tie(b[i], x, a[j]) > tie(b[j], y, a[i]);
  });
  for (int i : order) cout << a[i] << '\n';
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