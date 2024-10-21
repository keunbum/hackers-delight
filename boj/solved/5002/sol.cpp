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
  int X;
  cin >> X;
  string s;
  cin >> s;
  int M = 0;
  int W = 0;
  while (!s.empty()) {
    M += s[0] == 'M';
    W += s[0] == 'W';
    if (abs(M - W) <= X) {
      s.erase(s.begin());
      continue;
    }      
    M -= s[0] == 'M';
    W -= s[0] == 'W';
    if (s.size() == 1 || s[0] == s[1]) {
      break;
    }
    M += s[1] == 'M';
    W += s[1] == 'W';
    s.erase(s.begin() + 1);
  }
  cout << M + W << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
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