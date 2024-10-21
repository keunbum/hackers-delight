#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<string> solution(vector<vector<string>> plans) {
  vector<int> order(plans.size());
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return Encode(plans[i][1]) < Encode(plans[j][1]);
  });
  int cur_time = 0;
  vector<pair<int, int>> stk;
  vector<string> ret;
  for (int i : order) {
    while (!stk.empty() && cur_time + Encode(plans[stk.back()][1]) + stoi(plans[stk.back()][2]) <= Encode(plans[i][1])) {
      ret.push_back(plans[stk.back()][0]);
      stk.pop_back();
    }  
    stk.emplace_back(i, stoi(plans[i][2]));
  }
  while (!skt.empty()) {
    // ..
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
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