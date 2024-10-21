#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<int> menu, vector<int> order, int k) {
  vector<int> que(1, 0);
  int b = 0;
  int i = 1;
  int T = 0;
  int ret = 0;
  while (b < (int) que.size()) {
    debug(T, b, que, (int) que.size() - b);
    int j = que[b];
    if (k * j < T) {
      T += menu[order[j]];
    } else {
      T = k * j + menu[order[j]];
    }
    debug(T);
    while (i < (int) order.size() && k * i < T) {
      que.push_back(i);
      i += 1;
    }
    ret = max(ret, (int) que.size() - b);
    b += 1;
    if (b == (int) que.size() && i < (int) order.size()) {
      que.push_back(i);
      i += 1;
    }
  }
  debug(ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({5, 12, 30}, {1, 2, 0, 1}, 10);
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
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/