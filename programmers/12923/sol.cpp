#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(long long begin, long long end) {
  vector<int> ret(end - begin + 1, 0);
  for (int i = begin; i <= end; i++) {
    ret[i - begin] = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0 && i / j <= (int) 1e7) {
        ret[i - begin] = i / j;
        break;
      }
    }
  }
  if (begin == 1) {
    ret[0] = 0;
  }
  debug(ret);
  return ret;  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution(1, 10);
  solution(999999999, 1000000000);
  solution(9999999, 10000002);
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