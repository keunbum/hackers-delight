#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

string solution(vector<string> a, vector<string> b, vector<string> c) {
  int n = (int) a.size();
  int m = (int) b.size();
  int k = (int) c.size();
  for (int bits = 0; bits < (1 << k); ++bits) {
    int p = 0;
    int q = 0;
    bool ok = true;
    for (int i = 0; i < k; ++i) {
      if ((bits >> i) & 1) {
        if (q < m && b[q] == c[i]) {
          q += 1;
          continue;
        }
      } else {
        if (p < n && a[p] == c[i]) {
          p += 1;
          continue;
        }
      }
      ok = false;
      break;
    }
    if (ok) {
      return "Yes";
    }
  }
  return "No";
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