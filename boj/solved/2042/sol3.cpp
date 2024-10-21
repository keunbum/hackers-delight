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

  void modify(int x, const T& by) {
    while (x >= 0) {
      a[x] += by;
      x = (x & (x + 1)) - 1;
    }
  }

  T get(int x) const {
    T v{};
    while (x < n) {
      v += a[x];
      x |= x + 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n);
  fenwick<long long> fenw(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    fenw.modify(i, a[i]);
  }
  m += k;
  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd & 1) {
      int i;
      long long x;
      cin >> i >> x;
      --i;
      fenw.modify(i, x - a[i]);
      a[i] = x;
    } else {
      int i, j;
      cin >> i >> j;
      --i; --j;
      cout << fenw.get(i) - fenw.get(j + 1) << '\n';
    }
  }
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