#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> in(n), out(n);
  for (int i = 0; i < n; ++i) {
    cin >> out[i] >> in[i];
  }
  {
    int A = 0, B = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int v = min(A, out[i]);
      A -= v;
      ans += out[i] - v;
      B -= out[i] - v;
      B += in[i];
      if (i % k == 0) {
        A += B;
        B = 0;
      }
    }
    cout << ans << ' ';
  }
  {
    int A = 0, B = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int v = min(B, out[i]);
      B -= v;
      ans += v;
      A -= out[i] - v;
      B += in[i];
      if (i % k == 0) {
        A += B;
        B = 0;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
