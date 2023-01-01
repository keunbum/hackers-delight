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
  int n;
  cin >> n;
  array<vector<int>, 2> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[0].push_back(x);
  }
  for (int i = 1; i <= n + n; i++) {
    if (find(a[0].begin(), a[0].end(), i) == a[0].end()) {
      a[1].push_back(i);
    }
  }
  for (int i = 0; i < 2; i++) {
    sort(a[i].begin(), a[i].end());
  }
  int top = 0;
  int x = 0;
  while (!a[0].empty() && !a[1].empty()) {
    auto it = upper_bound(a[x].begin(), a[x].end(), top);
    if (it == a[x].end()) {
      top = -1;
    } else {
      top = *it;
      a[x].erase(it);
    }
    x ^= 1;
  }
  cout << a[1].size() << '\n' << a[0].size() << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/