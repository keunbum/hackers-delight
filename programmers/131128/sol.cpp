#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

string solution(string x, string y) {
  array<int, 128> cntA{};
  for (char ch : x) {
    cntA[(int) ch] += 1;
  }
  array<int, 128> cntB{};
  for (char ch : y) {
    cntB[(int) ch] += 1;
  }
  string ret;
  for (char ch : string("9876543210")) {
    ret += string(min(cntA[(int) ch], cntB[(int) ch]), ch);
  }
  return ret == "" ? "-1" : (ret[0] == '0' ? "0" : ret);
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
  * int overflow, array bounds (habituation of assert)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/