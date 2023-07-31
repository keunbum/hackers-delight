#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

template <typename T>
struct RMQ {
  int n;
  vector<T> tree;

  RMQ(int n) : n(n), tree(n << 1) {}

  void Init(const T init_value = numeric_limits<T>::max()) {
    tree[0] = init_value;
    int pos;
    for (pos = 0; pos < n; ++pos) {
      T x;
      cin >> x;
      tree[pos + n] = x;
    }
    for (pos = n - 1; pos > 0; --pos) {
      tree[pos] = min(tree[pos << 1], tree[pos << 1 | 1]);
    }
  }
  
  void Update(int pos, const T val) {
    for (tree[pos += n] = val; pos > 1; pos /= 2) {
      tree[pos / 2] = min(tree[pos], tree[pos ^ 1]);
    }
  }
  
  // [b, e)
  T Query(int b, int e) {
    T res = tree[0];
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) res = min(res, tree[b++]);
      if (e % 2) res = min(res, tree[--e]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  RMQ<int> q(n);
  q.Init();
  while (m--) {
    int x, y;
    cin >> x >> y;
    cout << q.Query(--x, y) << '\n';
  }
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