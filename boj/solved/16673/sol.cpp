#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int c, k, p;
  cin >> c >> k >> p;
  long long res = 0;
  for (int i = 1 ; i <= c; i++) {
    res += (long long) i * (p * i + k);
  }
  cout << res << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to them.
  * internalization of problem statements.
  * simplify. a step-by-step approach.
  * readability is important.
  * don't get excited. deep breathing. keep calm.
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
*/