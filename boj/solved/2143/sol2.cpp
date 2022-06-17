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
  int T;
  cin >> T;
  auto GetSum = [&]() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += a[j];
        ret.push_back(sum);
      }
    }
    sort(ret.begin(), ret.end());
    return ret;
  };
  auto sumA = GetSum();
  auto sumB = GetSum();
  int L = 0;
  int R = (int) sumB.size() - 1;
  long long ans = 0;
  while (L < (int) sumA.size() && R >= 0) {
    int S = sumA[L] + sumB[R];
    if (S > T) {
      R -= 1;
    } else
    if (S < T) {
      L += 1;
    } else {
      int cntL = 1;
      while (L + 1 < (int) sumA.size() && sumA[L + 1] == sumA[L]) {
        L += 1;
        cntL += 1;
      }
      int cntR = 1;
      while (R - 1 >= 0 && sumB[R - 1] == sumB[R]) {
        R -= 1;
        cntR += 1;
      }
      ans += (long long) cntL * cntR;
      L += 1;
      R -= 1;
    }
  }
  cout << ans << '\n';
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