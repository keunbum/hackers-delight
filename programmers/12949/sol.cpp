#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<vector<int>> solution(vector<vector<int>> a, vector<vector<int>> b) {
  vector<vector<int>> ret(a.size(), vector<int>(b[0].size(), 0));
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) b[0].size(); j++) {
      for (int k = 0; k < (int) a[0].size(); k++) {
        ret[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return ret;
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