#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

string solution(string s, int k) {
  int n = (int) s.size();
  string ret;
  for (int i = 0; i < n; i++) {
    while (k > 0 && !ret.empty() && ret.back() < s[i]) {
      ret.pop_back();
      k -= 1;
    }
    ret.push_back(s[i]);
  }
  ret.resize(ret.size() - k);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  debug(solution("1924", 2));
  debug(solution("1231234", 3));
  debug(solution("4177252841", 4));
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