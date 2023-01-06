#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

template <typename T>
class fenwick {
 public:
  int n;
  vector<T> a;

  fenwick(int _n) : n(_n), a(n) {}

  void modify(int x, T by) {
    while (x < n) {
      a[x] ^= by;
      x |= x + 1;
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v ^= a[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  fenwick<int> fenw(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    fenw.modify(i, x);
  }
  int ans = 0;
  while (q--) {
    int s, e;
    cin >> s >> e;
    --s; --e;
    ans ^= fenw.get(e) ^ fenw.get(s - 1);
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