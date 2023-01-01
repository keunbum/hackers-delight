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
  vector<int> a(n + n, 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    --x;
    a[x] = 0;
  }
  int t = 0;
  int top = -1;
  vector<int> cnt(2, n);
  while (cnt[0] > 0 && cnt[1] > 0) {
    int i;
    for (i = top + 1; i < n + n; i++) {
      if (a[i] == t) {
        break;
      }
    }
    if (i == n + n) {
      top = -1;
    } else {
      top = i;
      a[i] = -1;
      cnt[t] -= 1;
    }
    t ^= 1;
  }
  cout << cnt[1] << '\n' << cnt[0] << '\n';
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
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/