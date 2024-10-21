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
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> stk;
  vector<pair<int, int>> pairs;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') stk.push_back(i); else
    if (s[i] == ')') {
      pairs.emplace_back(stk.back(), i);
      stk.pop_back();
    }
  }
  vector<string> res;
  int m = (int) pairs.size();
  assert(1 <= m && m <= 10);
  for (int bits = 1; bits < (1 << m); bits++) {
    vector<bool> used(n, true);
    for (int i = 0; i < m; i++) {
      if (((bits >> i) & 1) == 1) {
        used[pairs[i].first] = used[pairs[i].second] = false;
      }
    }
    string cur;
    for (int i = 0; i < n; i++) {
      cur += used[i] ? string(1, s[i]) : "";
    }
    res.push_back(cur);
  }
  sort(res.begin(), res.end());
  res.resize(unique(res.begin(), res.end()) - res.begin());
  for (auto& e : res) {
    cout << e << '\n';
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