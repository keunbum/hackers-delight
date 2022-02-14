#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
  int ret = 0;
  for (char ch : name) {
    ret += min(ch - 'A', 26 - (ch - 'A'));
  }
  vector<int> a;
  int n = (int) name.size();
  for (int i = 1; i < n; i++) {
    if (name[i] == 'A') {
      continue;
    }
    a.push_back(i);
  }
  // clock
  int sz = (int) a.size();
  int mn = (sz == 0) ? 0 : n;
  for (int i = 0; i < sz; i++) {
    int cur = a[i];
    if (i < sz - 1) {
      cur += a[i] + n - a[i + 1];
    }
    mn = min(mn, cur);
  }
  // counter
  for (int i = sz - 1; i >= 0; i--) {
    int cur = n - a[i];
    if (i > 0) {
      cur += n - a[i] + a[i - 1];
    }
    mn = min(mn, cur);
  }
  ret += mn;
  return ret;
}
/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to their limitations
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. keep calm
  
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
*/