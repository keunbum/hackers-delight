#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> y(n);
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }
  vector<int> cnts(n, 0);
  for (int i = 0; i < n; i++) {
    long long dx = 1;
    long long dy = (long long) -2e9;
    for (int j = i + 1; j < n; j++) {
      long long cx = j - i;
      long long cy = y[j] - y[i];
      debug(cx, cy, dx, dy);
      if (cy * dx > cx * dy) {
        cnts[i] += 1;
        cnts[j] += 1;
        dx = cx;
        dy = cy;
      }
    }
  }
  cout << *max_element(cnts.begin(), cnts.end()) << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
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