#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = (int) 1e4;
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> cnt(MAX + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]] += 1;
  }
  while (q--) {
    int c;
    cin >> c;
    if (c == 1) {
      int x;
      cin >> x;
      if (x == 0) {
        cout << (n > 1 && cnt[0] > 0) << '\n';
        continue;
      }
      bool found = false;
      for (int y = max(1, x / MAX); y * y <= x; ++y) {
        int z;
        if ((x % y == 0 && (z = x / y) <= MAX) && ((y != z && cnt[y] > 0 && cnt[z] > 0) || (y == z && cnt[y] > 1))) {
          found = true;
          break;
        }
      }
      cout << found << '\n';
    } else {
      int i;
      cin >> i;
      --i;
      cnt[a[i]] -= 1;
      a[i] = 0;
      cnt[0] += 1;
    }
  }
  return 0;
}
