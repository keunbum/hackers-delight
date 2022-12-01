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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  const int inf = (int) 1e9 + 1;
  array<int, 3> best{inf, inf, inf};
  for (int i = 0; i < n; i++) {
    int L = i + 1;
    int R = (int) a.size() - 1;
    while (L < R) {
      long long S = (long long) a[i] + a[L] + a[R];
      if (abs(S) < abs(accumulate(best.begin(), best.end(), 0LL))) {
        best = {a[i], a[L], a[R]};
        if (S == 0) {
          break;
        }
      }
      if (S < 0) {
        L += 1;
      } else {
        R -= 1;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    cout << best[i] << " \n"[i == 2];
  }
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