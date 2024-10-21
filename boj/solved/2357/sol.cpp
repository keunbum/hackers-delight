#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

template <typename T, class F = function<T(const T&, const T&)>>
struct SegTree {
  size_t n;
  F func;
  vector<T> tree;

  SegTree(size_t _n, const F& f, T _init_value) : n(_n), func(f), tree(2 * n, _init_value) {}
  
  void Update(size_t pos, size_t val) {
    for (tree[pos += n] = val; pos > 1; pos /= 2)
      tree[pos / 2] = func(tree[pos], tree[pos ^ 1]);
  }
  
  // [b, e)
  T Query(size_t b, size_t e) {
    T res = tree[0];
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) res = func(res, tree[b++]);
      if (e % 2) res = func(res, tree[--e]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  SegTree<int> maxTree(n, [](int a, int b) { return max(a, b); }, numeric_limits<int>::min());
  SegTree<int> minTree(n, [](int a, int b) { return min(a, b); }, numeric_limits<int>::max());
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    maxTree.Update(i, x);
    minTree.Update(i, x);
  }
  while (m--) {
    int i, j;
    cin >> i >> j;
    --i;
    cout << minTree.Query(i, j) << " " << maxTree.Query(i, j) << '\n';
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