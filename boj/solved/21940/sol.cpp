#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int inf = (int) 1e9;
  vector<vector<int>> d(n, vector<int>(n, inf));
  for (int i = 0; i < n; ++i) d[i][i] = 0;
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    --x; --y;
    d[x][y] = w;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      if (d[i][k] == inf) continue;
      for (int j = 0; j < n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int k;
  cin >> k;
  vector<int> cs(k);
  for (int i = 0; i < k; ++i) {
    cin >> cs[i];
    --cs[i];
  }
  int s_max = inf;
  vector<int> res;
  for (int x = 0; x < n; ++x) {
    int mx = 0;
    for (int c : cs) {
      mx = max(mx, d[c][x] + d[x][c]);
    }
    if (mx < s_max) {
      s_max = mx;
      vector<int>().swap(res);
    }
    if (mx == s_max) res.push_back(x);
  }
  for (int x : res) cout << x + 1 << ' ';
  return 0;
}
