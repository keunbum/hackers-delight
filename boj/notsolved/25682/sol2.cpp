#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

char s[N + 1];
int p[N + 1][N + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  int ans = h * w;
  for (int i = 0; i < h; i++) {
    cin >> s;
    for (int j = 0; j < w; j++) {
      p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + ((s[j] == 'W') ^ ((i + j) % 2));
    }
  }
  for (int i = k; i <= h; i++) {
    for (int j = k; j <= w; j++) {
      int cnt = p[i][j] - p[i][j - k] - p[i - k][j] + p[i - k][j - k];
      ans = min({ans, cnt, k * k - cnt});
    }
  }
  cout << ans << '\n';
  return 0;
}
