#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int k, vector<int> a) {
  sort(a.begin(), a.end());
  vector<int> b(a);
  b.resize(unique(b.begin(), b.end()) - b.begin());
  for (int i = 0; i < (int) b.size(); i++) {
    b[i] = upper_bound(a.begin(), a.end(), b[i]) - lower_bound(a.begin(), a.end(), b[i]);
  }
  sort(b.begin(), b.end());
  partial_sum(b.begin(), b.end(), b.begin());
  int r = (int) a.size() - k;
  int i = (int) (lower_bound(b.begin(), b.end(), r + 1) - b.begin());
  return (int) b.size() - i;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution(6, {1, 3, 2, 5, 4, 5, 2, 3});
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