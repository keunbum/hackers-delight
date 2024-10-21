#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

char Decode(int x) {
  if (x < 10) {
    return (char) x + '0';
  }
  return (char) x - 10 + 'A';
}

string Decode(int n, int base) {
  string ret;
  while (n > 0) {
    ret += Decode(n % base);
    n /= base;
  }
  return ret.empty() ? "0" : ret;
}

string solution(int n, int t, int m, int p) {
  debug(n, t, m, t * m, p);
  --p;
  string s;
  {
    int x = 0;
    while (true) {
      string ss = Decode(x, n);
      debug(x, ss);
      int i = 0;
      for (i = (int) ss.size() - 1; i >= 0 && (int) s.size() < t * m; i--) {
        s += ss[i];
      }
      if ((int) s.size() == t * m) {
        break;
      }
      x += 1;
    }
  }
  debug(s);
  string ret;
  for (int i = 0; i < t; i++) {
    int j = m * i + p;
    debug(j);
    assert(0 <= j && j < (int) s.size());
    ret += s[j];
  }
  debug(ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution(16, 16, 2, 1);
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
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/