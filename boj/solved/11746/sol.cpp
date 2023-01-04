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
  long long k;
  cin >> n >> k;
  debug(n, k);
  vector<int> h(n);
  int max_h = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    max_h = max(max_h, h[i]);
  }
  int low = max_h;
  int high = (int) 1e9 + n;
  while (low < high) {
    int mid = low + (high - low + 1) / 2;
    debug(low, mid, high);
    vector<bool> oks(n, true);
    vector<long long> cntL(n, 0);
    vector<long long> cntR(n, 0);
    {
      int L = n - 1;
      for (int i = n - 1; i >= 0; i--) {
        cntL[i] += -max(mid - h[i], 0) + (i - L);
        while (L >= 0 && h[L] < mid - (i - L)) {
          cntL[i] += mid - (i - L) - h[L];
          L -= 1;
        }
        if (i < n - 1) {
          cntL[i] += cntL[i + 1];
        }
        oks[i] = oks[i] & (L >= 0);
        L -= (L == i);
      }
    }
    {
      int R = 0;
      for (int i = 0; i < n; i++) {
        cntR[i] += -max(mid - h[i], 0) + (R - i);
        while (R < n && h[R] < mid - (R - i)) {
          cntR[i] += mid - (R - i) - h[R];
          R += 1;
        }
        if (i > 0) {
          cntR[i] += cntR[i - 1];
        }
        oks[i] = oks[i] & (R < n);
        R += (R == i);
      }
    }
//      debug(oks);
//      debug(cnt);
    bool ok = false;
    for (int i = 0; i < n; i++) {
      ok |= (oks[i] & (cntL[i] + cntR[i] + max(mid - h[i], 0) <= k));
    }
    if (ok) {
      low = mid;
    } else {
      high = mid - 1;
    }
    debug(1.0 * clock() / CLOCKS_PER_SEC);
  }
  cout << low << '\n';
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