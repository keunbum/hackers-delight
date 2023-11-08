#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAXN = (int) 2e6;
  bitset<MAXN + 1> prime;
  prime.set();
  prime[1] = 0;
  for (int i = 2; i * i <= MAXN; ++i) {
    if (prime[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        prime[j] = 0;
      }
    }
  }
  vector<int> res;
  for (int i = 2; i <= MAXN; ++i) {
    if (!prime[i]) {
      continue;
    }
    int j = 0;
    int x = i;
    while (x > 0) {
      j = j * 10 + x % 10;
      x /= 10;
    }
    if (i == j) {
      res.push_back(i);
    }
  }
  int n;
  cin >> n;
  cout << (*lower_bound(res.begin(), res.end(), n)) << '\n';
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