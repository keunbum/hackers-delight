#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int n, vector<int> a, int w) {
  int unit = w + w + 1;
  debug(unit);
  int ret = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    int cover = 0;
    if (i == 0) {
      cover += max(a[i] - 1 - w, 0);
    } else {
      cover += max(a[i] - a[i - 1] - (w + w + 1), 0);
    }
    debug(i, cover);
    ret += (cover + unit - 1) / unit;
  }
  {
    int cover = max(n - a.back() - w, 0);
    ret += (cover + unit - 1) / unit;
  }
  debug(ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution(11, {4, 11}, 1);
  solution(16, {9}, 2);
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
  * DON'T GET STUCK ON ONE APPROACH(feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/