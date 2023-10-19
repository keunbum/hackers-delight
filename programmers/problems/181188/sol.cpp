#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int solution(vector<vector<int>> targets) {
  vector<pair<int, int>> a;
  for (auto& t : targets) {
    a.emplace_back(t[0], +1);
    a.emplace_back(t[1], -1);
  }
  vector<int> order(a.size());
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  int ret = 0;
  vector<bool> used(a.size() / 2, false);
  vector<int> stk;
  for (int i : order) {
    auto&[x, t] = a[i];
    if (t < 0) {
      if (!used[i / 2]) {
        ret += 1;
        while (!stk.empty()) {
          used[stk.back()] = true;
          stk.pop_back();
        }
      }
    } else {
      stk.push_back(i / 2);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto res = solution( {{4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4}});
  debug(res);
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