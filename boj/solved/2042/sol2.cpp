#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct fenwick {
  int n;
  vector<T> fenw;

  fenwick(int _n) : n(_n), fenw(n) {}

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    fenw.modify(i, a[i]);
  }
  m += k;
  while (m--) {
    int x;
    cin >> x;
    if (x == 1) {
      int y;
      long long z;
      cin >> y >> z;
      --y;
      fenw.modify(y, z - a[y]);
      a[y] = z;
    } else {
      int y, z;
      cin >> y >> z;
      --y; --z;
      cout << fenw.get(z) - fenw.get(y - 1) << '\n';
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
  * don't lose your pace. deep breathing. keep calm
  
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
*/