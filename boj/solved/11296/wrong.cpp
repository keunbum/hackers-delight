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
  int n;
  cin >> n;
  cout << fixed << setprecision(2);
  while (n--) {
    long double x;
    char d, c, p;
    cin >> x >> d >> c >> p;
    const long double a[] = {.55, .7, .8, .85, .9, .95};
    int i = string("RGBYOW").find(d);
    x *= a[i];
    if (c == 'C') {
      x *= 0.95;
    }
    if (p == 'C') {
      x = (int) (10 * x + 0.4) / 10.0;
    } else {
      x = (int) (100 * x + 0.5) / 100.0;
    }
    cout << "$" << x << '\n';
  }
  return 0;
}
