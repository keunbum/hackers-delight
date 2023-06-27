#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, h, w;
  cin >> n >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; ++i) {
    cin >> s[i];
  }
  string ans(n, '?');
  for (int j = 0; j < w * n; j++) {
    char ch = '?';
    for (int i = 0; i < h; ++i) {
      if (s[i][j] != '?') {
        ch = s[i][j];
      }
    }
    if (ch != '?') {
      ans[j / w] = ch;
    }
  }
  cout << ans << '\n';
  return 0;
}
