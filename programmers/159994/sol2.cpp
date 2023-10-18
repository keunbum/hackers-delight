#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

string solution(vector<string> a, vector<string> b, vector<string> c) {
  string ret = "No";
  int k = (int) c.size();
  int p = 0;
  int q = 0;
  function<void(int)> DFS = [&](int v) {
    if (v == k) {
      ret = "Yes";
      return;
    }
    if (p < (int) a.size() && a[p] == c[v]) {
      p += 1;
      DFS(v + 1);
      p -= 1;
    }
    if (q < (int) b.size() && b[q] == c[v]) {
      q += 1;
      DFS(v + 1);
      q -= 1;
    }
  };
  DFS(0);
  return ret;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  
 * stuff you should look for
  * 0-based or 1-based?
  * off-by-one error
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