#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<int> solution(vector<int> a, int k) {
  int n = (int) a.size();
  int L = 0;
  int R = 0;
  int sum = 0;
  int i = 0, j = n;
  while (L < n) {
    while (R < n && sum + a[R] <= k) {
      sum += a[R];
      R += 1;
    }
    if (sum == k && j - i > R - L) {
      i = L;
      j = R;
    }
    sum -= a[L];
    L += 1;
  }
  return {i, j - 1};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto res = solution({1, 1, 1, 2, 3, 4, 5}, 5);
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