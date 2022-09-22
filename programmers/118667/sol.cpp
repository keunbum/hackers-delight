#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<int> que, vector<int> que2) {
  long long sum1 = accumulate(que.begin(), que.end(), 0LL);
  long long sum2 = accumulate(que2.begin(), que2.end(), 0LL);
  int init_p = 0;
  int init_q = (int) que.size();
  int p = init_p;
  int q = init_q;
  que.insert(que.end(), que2.begin(), que2.end());
  int cost = 0;
  int chk = 0;
  while (p != q && chk != 3) {
    debug(p, q, sum1, sum2);
    if (sum1 == sum2) {
      debug(cost);
      return cost;
    }
    if (sum1 < sum2) {
      sum1 += que[q];
      sum2 -= que[q];
      q = (q + 1) % que.size();
      chk |= ((q == init_p) << 0);
    } else {
      sum1 -= que[p];
      sum2 += que[p];
      p = (p + 1) % que.size();
      chk |= ((p == init_q) << 1);
    }
    cost += 1;
  }
  debug(-1);
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({3, 2, 7, 2},	{4, 6, 5, 1});
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * keep calm
  
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