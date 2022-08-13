#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

bool IsPrime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
  return true;
}

void Dfs(int n, int x) {
  if (n == 0) {
    cout << x << '\n';
    return;
  }
  for (int i = (x == 0 ? 1 : 0); i <= 9; i++) {
    int y = x * 10 + i;
    if (IsPrime(y)) {
      Dfs(n - 1, y);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  Dfs(n, 0);
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