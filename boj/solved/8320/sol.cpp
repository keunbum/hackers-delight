#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int x = 1; x <= n; ++x) {
    for (int i = 1; i * i <= x; ++i) {
      ans += (x % i == 0);
    }
  }
  cout << ans << '\n';
  return 0;
}
