#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(string dirs) {
  set<pair<pair<int, int>, pair<int, int>>> s;
  int x = 0;
  int y = 0;
  int ret = 0;
  for (char ch : dirs) {
    int nx = x;
    int ny = y;
    if (ch == 'U') ++ny;
    if (ch == 'D') --ny;
    if (ch == 'R') ++nx;
    if (ch == 'L') --nx;
    if (abs(nx) > 5 || abs(ny) > 5) continue;
    auto A = make_pair(x, y);
    auto B = make_pair(nx, ny);
    if (A > B) swap(A, B);
    ret += s.emplace(A, B).second;
    x = nx;
    y = ny;
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