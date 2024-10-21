#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

string solution(string s) {
  s += ' ';
  const long long inf = (long long) 9e18;
  long long mn = inf;
  long long mx = -inf;
  long long v = 0;
  int sign = 1;
  for (char ch : s) {
    if (ch == ' ') {
      v *= sign;
      mn = min(mn, v);
      mx = max(mx, v);
      v = 0;
      sign = 1;
    } else
    if (ch == '-') {
      sign = -1;
    } else {
      v = v * 10 + (int) (ch - '0');
    }
  }
  return to_string(mn) + " " + to_string(mx);
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