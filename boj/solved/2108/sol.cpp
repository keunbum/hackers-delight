#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

int Mode(valarray<int>& a) {
  array<int, 8001> c{};
  for (int x : a) c[x + 4000] += 1;
  int p = (int) (max_element(c.begin(), c.end()) - c.begin());
  for (int i = p + 1; i <= 8000; ++i) if (c[i] == c[p]) return i;
  return p;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  valarray<int> a(n);
  for (int& x : a) cin >> x;
  nth_element(begin(a), begin(a) + n / 2, end(a));
  double avg = 1.0 * a.sum() / n;
  int sign = avg > 1e-9 ? 1 : -1;
  cout << sign * (int) (sign* avg + 0.5) << '\n'
       << a[n / 2] << '\n'
       << Mode(a) - 4000 << '\n'
       << a.max() - a.min() << '\n'; 
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