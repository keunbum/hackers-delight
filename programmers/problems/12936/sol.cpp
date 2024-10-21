#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(int n, long long k) {
  vector<long long> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
  }
  vector<int> ret;
  vector<bool> used(n, false);
  for (int i = 0; i < n; i++) {
    int j = (k - 1) / fact[n - i - 1];
    int t = -1;
    for (int p = 0; p < n; p++) {
      if (!used[p]) {
        t += 1;
        if (t == j) {
          used[p] = true;
          ret.push_back(p + 1);
          break;
        }
      }
    }
    k -= j * fact[n - i - 1];
  }
  assert(used == vector<bool>(n, true));
  return ret;
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