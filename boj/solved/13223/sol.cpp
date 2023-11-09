#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

void Read(array<int, 3>& a) {
  string s;
  cin >> s;
  for (int i = 0; i < 3; ++i) {
    a[i] = 10 * (s[3 * i] - '0') + s[3 * i + 1] - '0';
  }
}

string F(int x) {
  string s = to_string(x);
  if ((int) s.size() == 1) s.insert(s.begin(), '0');
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  array<int, 3> a, b;
  Read(a);
  Read(b);
  for (int i = 0; i < 3; ++i) {
    b[i] -= a[i];
  }
  if (b[2] < 0) {
    b[2] += 60;
    b[1] -= 1;
  }
  if (b[1] < 0) {
    b[1] += 60;
    b[0] -= 1;
  }
  if (b[0] < 0) {
    b[0] += 24;
  }
  if (b == array<int, 3>{0, 0, 0}) {
    b[0] = 24;
  }
  for (int i = 0; i < 3; ++i) {
    if (i > 0) {
      cout << ":";
    }
    cout << F(b[i]);
  }
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