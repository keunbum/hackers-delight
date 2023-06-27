#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n - 2; ++i) {
    ans = max(ans, a[n - 1] - a[i + 1] - (a[i + 1] - a[i]));
  }
  for (int i = n - 1; i > 1; --i) {
    ans = max(ans, a[i - 1] - a[0] - (a[i] - a[i - 1]));
  }
  cout << ans << '\n';
  return 0;
}
