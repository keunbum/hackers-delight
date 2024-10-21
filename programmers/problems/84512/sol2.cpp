#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(string word) {
  const char* S = "AEIOU";
  array<int, 6> P;
  array<int, 6> pref;
  P[0] = 1;
  pref[0] = 1;
  for (int i = 1; i < 6; i++) {
    P[i] = P[i - 1] * 5;
    pref[i] = pref[i - 1] + P[i];
  }
  debug(P);
  int v = 0;
  for (int i = 0; i < (int) word.size(); i++) {
    int j = (int) (strchr(S, word[i]) - S);
    v += j * pref[4 - i] + 1;
    debug(v);
  }
  return v;
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution(argv[1]);
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