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
  const long long MAX = (long long) 1e10;
  function<void(int, int, long long)> Dfs = [&](int v, int p, long long x) {
    if (v == 10) {
      return;
    }
    if (v > 0) {
      string t = to_string(x);
      do {
        string a = t;
        long long y = stoll(a);
        string b = to_string(y + y);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a == b) {
          cout << y << '\n';
          cerr << y << '\n';
          debug(clock());
          break;
        }
      } while (prev_permutation(t.begin(), t.end()));
    }
    for (int i = p; i >= 0; i--) {
      Dfs(v + 1, i, x * 10 + i);
    }
  };
  Dfs(0, 9, 0);
  debug(clock());
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