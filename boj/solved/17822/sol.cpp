#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, tt;
  cin >> h >> w >> tt;
  vector<vector<int>> a(h, vector<int>(w));
  auto Debug = [&]() {
#ifdef LOCAL
    for (int i = 0; i < h; ++i) {
      cerr << "[";
      for (int j = 0; j < w; ++j) {
        if (j > 0) cerr << ", ";
        cerr << a[i][j];
      }
      cerr << "]" << endl;
    }
    cerr << endl;
#endif
  };
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) cin >> a[i][j];
  Debug();
  while (tt--) {
    int x, d, k;
    cin >> x >> d >> k;
//    cerr << x << " " << d << " " << k << endl;
    if (d == 0) k = w - k;
    for (int i = x - 1; i < h; i += x) {
      rotate(a[i].begin(), a[i].begin() + k, a[i].end());
    }
    Debug();
    auto na(a);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        int jj = (j + 1) % w;
        if (a[i][j] != 0 && a[i][j] == a[i][jj]) {
          na[i][j] = na[i][jj] = 0;
        }
      }
    }
    for (int j = 0; j < w; ++j) {
      for (int i = 0; i < h - 1; ++i) {
        int ii = i + 1;
        if (a[i][j] != 0 && a[i][j] == a[ii][j]) {
          na[i][j] = na[ii][j] = 0;
        }
      }
    }
    swap(a, na);
    if (a == na) {
      int sum = 0;
      int cnt = 0;
      for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
        sum += a[i][j];
        cnt += a[i][j] > 0;
      }
      for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) if (a[i][j] != 0) a[i][j] += -(a[i][j] * cnt > sum) + (a[i][j] * cnt < sum);
    }
    Debug();
  }
  int ans = 0;
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) ans += a[i][j];
  cout << ans << '\n';
  return 0;
}
