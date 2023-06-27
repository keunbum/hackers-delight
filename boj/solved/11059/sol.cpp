#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> pref(n + 1);
  pref[0] = 0;
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + (int) (s[i] - '0');
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; j += 2) {
      int k = (i + j) / 2;
      if (pref[k + 1] - pref[i] == pref[j + 1] - pref[k + 1]) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
