#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<vector<int>> land) {
  array<int, 4> a;
  for (int i = 0; i < 4; i++) {
    a[i] = land[0][i];
  }
  for (int i = 1; i < (int) land.size(); i++) {
    array<int, 4> new_a;
    for (int j = 0; j < 4; j++) {
      int mx = 0;
      for (int k = 0; k < 4; k++) {
        if (k != j) {
          mx = max(mx, a[k]);
        }
      }
      new_a[j] = mx + land[i][j];
    }
    swap(a, new_a);
  }
  return *max_element(a.begin(), a.end());
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