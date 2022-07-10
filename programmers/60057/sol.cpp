#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int Compress(const string& s, int l) {
  string ret;
  int cnt = 1;
  string pre;
  for (int i = 0; i < (int) s.size(); i += l) {
    if (i == 0) {
      pre = s.substr(i, l);
      continue;
    }
    string cur = s.substr(i, l);
    if (pre == cur) {
      cnt += 1;
    } else {
      ret += (cnt == 1 ? "" : to_string(cnt)) + pre;
      pre = cur;
      cnt = 1;
    } 
  }
  ret += (cnt == 1 ? "" : to_string(cnt)) + pre;
  debug(s, l, ret);
  return (int) ret.size();
}

int solution(string s) {
  int ret = (int) s.size();
  for (int i = 1; i < (int) s.size(); i++) {
    ret = min(ret, Compress(s, i));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution("aabbaccc");
  solution("ababcdcdababcdcd");
  solution("abcabcdede");
  solution("abcabcabcabcdededededede");
  solution("xababcdcdababcdcd");
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