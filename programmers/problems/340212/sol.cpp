#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int solution(vector<int> diffs, vector<int> times, long long limit) {
  int n = int(diffs.size());
  int low = 1;
  int high = int(1e5);
  while (low < high) {
    int mid = (low + high) >> 1;
    long long s = 0;
    for (int i = 0; i < n; ++i) {
      s += times[i] + 1LL * max(diffs[i] - mid, 0) * (times[i] + (i > 0 ? times[i - 1] : 0));
    }
    if (s <= limit) {
      high = mid;
    } else {
      low = mid + 1;
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
  * Do I have to solve like this?
  
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
