#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(string command) {
  int x = 0;
  int y = 0;
  int dx = 0;
  int dy = 1;
  for (char ch : command) {
    if (ch == 'R') {
      tie(dx, dy) = make_pair(dy, -dx);
    }
    if (ch == 'L') {
      tie(dx, dy) = make_pair(-dy, dx);
    }
    if (ch == 'G') {
      x += dx;
      y += dy;
    }
    if (ch == 'B') {
      x -= dx;
      y -= dy;
    }
  }
  return {x, y};
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
  * deep breathing. keep calm
  
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