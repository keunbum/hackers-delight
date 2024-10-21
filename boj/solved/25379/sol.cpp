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
  int beg = 0;
  vector<int> evens;
  vector<int> odds;
  while (beg < n) {
    int end = beg + 1;
    while (end < n && a[end] % 2 == a[beg] % 2) {
      end += 1;
    }
    if (a[beg] % 2 == 0) {
      evens.push_back(end - beg);
    } else {
      odds.push_back(end - beg);
    }
    beg = end;
  }
  long long ans = (long long) 9e18;
  for (int rot = 0; rot < 2; rot++) {
    int ne = (int) evens.size();
    vector<int> sum_even(ne + 1, 0);
    for (int i = 0; i < ne; i++) {
      sum_even[i + 1] = sum_even[i] + evens[i];
    }
    debug(evens);
    debug(sum_even);
    int no = (int) odds.size();
    vector<int> sum_odd(no + 1, 0);
    for (int i = 0; i < no; i++) {
      sum_odd[i + 1] = sum_odd[i] + odds[i];
    }
    debug(odds);
    debug(sum_odd);
    assert(abs(ne - no) <= 1);
    {
      long long cur = 0;
      for (int i = 0; i < ne; i++) {
        cur += 1LL * sum_odd[i - (a[0] % 2 == 0) + 1] * evens[i];
      }
      ans = min(ans, cur);
    }
    {
      long long cur = 0;
      for (int i = 0; i < no; i++) {
        cur += 1LL * (sum_even[ne - 1 + 1] - sum_even[i - (a[0] % 2 == 1) + 1]) * odds[i];
      }
      ans = min(ans, cur);
    }
    if (rot == 1) {
      break;
    }
    reverse(a.begin(), a.end());
    reverse(evens.begin(), evens.end());
    reverse(odds.begin(), odds.end());
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
  * don't get excited. keep calm
  
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