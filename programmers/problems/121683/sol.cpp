#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

string solution(string s) {
  array<int, 128> cnt{};
  set<char> res;
  for (int i = 0; i < (int) s.size(); i++) {
    if (i > 0 && s[i] != s[i - 1] && cnt[(int) s[i]] > 0) {
      res.insert(s[i]);
    }
    cnt[(int) s[i]] += 1;
  }
  string ret(res.begin(), res.end());
  return (ret == "" ? "N" : ret);
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