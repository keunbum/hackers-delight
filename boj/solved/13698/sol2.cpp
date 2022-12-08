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
  string s;
  cin >> s;
  string t = "1002";
  for (char ch : s) {
    if (ch == 'A') swap(t[0], t[1]);
    if (ch == 'B') swap(t[0], t[2]);
    if (ch == 'C') swap(t[0], t[3]);
    if (ch == 'D') swap(t[1], t[2]);
    if (ch == 'E') swap(t[1], t[3]);
    if (ch == 'F') swap(t[2], t[3]);
  }
  cout << t.find('1') + 1 << '\n' << t.find('2') + 1 << '\n'; 
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