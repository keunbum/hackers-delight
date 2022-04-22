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
  const string S = "abc";
  cout << fixed << setprecision(3);
  int qq = 1;
  while (true) {
    array<long long, 3> a;
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }
    if (a[0] == 0) {
      break;
    }
    cout << "Triangle #" << qq << '\n';
    for (int i = 0; i < 3; i++) {
      if (a[i] == -1) {
        if (i == 2) {
          cout << S[i] << " = " << sqrt(a[0] * a[0] + a[1] * a[1]);
        } else {
          long long xx = a[2] * a[2] - a[1 - i] * a[1 - i];
          if (xx < 1) {
            cout << "Impossible.";
          } else {
            cout << S[i] << " = " << sqrt((double) xx);
          }
        }
      }
    }
    cout << "\n\n";
    qq += 1;
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
  * 0-based or 1-based?
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