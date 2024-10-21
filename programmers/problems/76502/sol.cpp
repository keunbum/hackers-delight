#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

char mp[128];

bool IsOk(const string&s) {
  vector<char> stk;
  debug(s);
  for (char ch : s) {
    if (strchr("([{", ch)) {
      stk.push_back(ch);
    } else {
      if (stk.empty() || stk.back() != mp[(int) ch]) {
        return false;
      }
      stk.pop_back();
    }
  }
  debug(stk);
  return stk.empty();
}

int solution(string s) {
  mp[')'] = '(';
  mp[']'] = '[';
  mp['}'] = '{';
  int ret = 0;
  for (int rot = 0; rot < (int) s.size(); rot++) {
    rotate(s.begin(), s.begin() + 1, s.end());
    ret += IsOk(s);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << solution("[](){}") << endl;
  cout << solution("}]()[{") << endl;
  cout << solution("[)(]") << endl;
  cout << solution("}}}") << endl;
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