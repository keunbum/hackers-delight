#include <bits/stdc++.h>

using namespace std;

struct segtree {
  int n;
  vector<long long> tree;

  segtree(int _n) : n(_n), tree(n + n - 1) {}

  template <typename T>
  void build(int x, int l, int r, const vector<T>& a) {
    if (l == r) {
      tree[x] = a[l];
      return;
    }
    int y = (l + r) / 2;
    int z = x + (y - l + 1) * 2;
    build(x + 1, l, y, a);
    build(z, y + 1, r, a);
    tree[x] = tree[x + 1] + tree[z];
  };

  void modify(int x, int l, int r, int p, long long v) {
    if (l == r) {
      tree[x] += v;
      return;
    }
    int y = (l + r) / 2;
    int z = x + (y - l + 1) * 2;
    if (p <= y) {
      modify(x + 1, l, y, p, v);
    } else {
      modify(z, y + 1, r, p, v);
    }
    tree[x] = tree[x + 1] + tree[z];
  }

  long long get(int x, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) {
      return tree[x];
    }
    int y = (l + r) / 2;
    int z = x + (y - l + 1) * 2;
    if (rr <= y) {
      return get(x + 1, l, y, ll, rr);
    }
    if (ll > y) {
      return get(z, y + 1, r, ll, rr);
    }
    return get(x + 1, l, y, ll, rr) + get(z, y + 1, r, ll, rr);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  segtree tree(n);
  tree.build(0, 0, n - 1, a);
  for (int _ = 0; _ < m + k; _++) {
    int x;
    cin >> x;
    if (x == 1) {
      int y;
      long long z;
      cin >> y >> z;
      --y;
      tree.modify(0, 0, n - 1, y, z - a[y]);
      a[y] = z;
    } else {
      int y, z;
      cin >> y >> z;
      --y; --z;
      cout << tree.get(0, 0, n - 1, y, z) << '\n';
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