#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int len, int limit, vector<int> weights) {
  int n = (int) weights.size();
  int passed = 0;
  int sec = 0;
  int id = 0;
  int sum = 0;
  vector<int> que;
  int beg = 0;
  while (passed < n) {
    if (beg < (int) que.size() && sec - que[beg] == len) {
      sum -= weights[passed];
      passed += 1;
      beg += 1;
    }
    if (id < n && sum + weights[id] <= limit) {
      que.push_back(sec);
      sum += weights[id];
      id += 1;
    }
    sec += 1;
  }
  return sec;
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