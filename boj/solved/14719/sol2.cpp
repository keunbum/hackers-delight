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
      a[x] += by;
      x |= x + 1;
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += a[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

struct node {
  int a = 0;
 
  inline void operator +=(node &other) {
    a = max(a, other.a);
  }
};  

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<int> a(w);
  vector<int> res(w);
  {
    fenwick<node> fenw(w);
    for (int i = 0; i < w; i++) {
      cin >> a[i];
      res[i] = fenw.get(i - 1).a;
      fenw.modify(i, {a[i]});
    }
  }
  {
    reverse(a.begin(), a.end());
    fenwick<node> fenw(w);
    for (int i = 0; i < w; i++) {
      res[w - 1 - i] = max(min(res[w - 1 - i], fenw.get(i - 1).a), a[i]) - a[i];
      fenw.modify(i, {a[i]});
    }
  }
  cout << accumulate(res.begin(), res.end(), 0) << '\n';    
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