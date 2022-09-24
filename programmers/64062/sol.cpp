#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<int> stones, int k) {
  int low = 1;
  int high = (int) 2e8;
  while (low < high) {
    int mid = (low + high + 1) / 2;
    int max_cnt = 0;
    int cnt = 0;
    for (int i = 0; i < (int) stones.size(); i++) {
      if (max(stones[i] - high, 0) == 0) {
        cnt += 1;
      } else {
        max_cnt = max(max_cnt, cnt);
        cnt = 0;
      }
    }
    max_cnt = max(max_cnt, cnt);
    if (max_cnt <= k) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  return low;
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
  * int overflow, array bounds (habituation of assert)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/