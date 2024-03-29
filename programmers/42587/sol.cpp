﻿#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<int> prios, int loc) {
  int n = (int) prios.size();
  vector<int> que(n);
  iota(que.begin(), que.end(), 0);
  int order = 0;
  for (int beg = 0; beg < (int) que.size(); beg++) {
    int id = que[beg];
    int max_id = *max_element(que.begin() + beg, que.end(), [&](int id, int jd) {
      return prios[id] < prios[jd];
    });
    if (prios[id] < prios[max_id]) {
      que.push_back(id);
      continue;
    }
    order += 1;
    if (id == loc) {
      return order;
    }
  }
  assert(false);
  return -1;    
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({2, 1, 3, 2}, 2);
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
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/