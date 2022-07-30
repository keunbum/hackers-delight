#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(string s) {
  if (s == "1") {
    return {0, 0};
  }
  int val = 0;
  for (char ch : s) {
    val += (ch == '1');
  }
  int trans_cnt = 1;
  int del_zeros = (int) s.size() - val;
  while (val != 1) {
    int total_len = 32 - __builtin_clz(val);
    val = __builtin_popcount(val);
    del_zeros += total_len - val;
    trans_cnt += 1;
  }
  return {trans_cnt, del_zeros};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  debug(solution("110010101001"));
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