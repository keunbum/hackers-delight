#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<int> a) {
  int n = (int) a.size();
  vector<int> sum(n + 1);
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
  }
  set<int> s;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      s.insert(sum[j + 1] - sum[i]);
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = i; j < n - 1; j++) {
      s.insert(sum[n] - sum[0] - (sum[j + 1] - sum[i]));
    }
  }
  return s.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({7,9,1,1,4});
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