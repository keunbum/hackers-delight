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
  long long L;
  cin >> s >> L;
  vector<bool> good(L, false);
  for (long long i = 2; i < L; i++) {
    if (good[i]) {
      continue;
    }
    int val = 0;
    for (int j = 0; j < (int) s.size(); j++) {
      val = (val * 10 + s[j] - '0') % i;
    }
    if (val == 0) {
      cout << "BAD " << i << '\n';
      return 0;
    }
    for (long long j = i * i; j < L; j += i) {
      good[j] = true;
    }
  }
  cout << "GOOD" << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * <= or <?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/