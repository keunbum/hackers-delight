#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  auto Solve = [&]() {
    vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      g = gcd(g, a[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      a[i] /= g;
      sum += a[i];
    }
    return make_pair(a, sum);
  };
  auto[a, s0] = Solve();
  auto[b, s1] = Solve();
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] != 0) {
      mx = max(mx, (a[i] + b[i] - 1) / b[i]);
    }
  }
  cout << s0 << ' ' << ((long long) mx * s1) << '\n';
  return 0;
}
