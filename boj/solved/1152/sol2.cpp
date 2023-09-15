#include <bits/stdc++.h>

using namespace std;

int score[] = {
  0, 2, 4, 6, 8, 10, 12, 14, 16, 18,
  20, 22, 24, 26, 28, 30, 32, 34, 36, 38,
  22, 24, 13, 16, 19, 25, 26, 27, 28, 30,
  35, 40, 0};
int nxt[] = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
  11, 12, 13, 14, 15, 16, 17, 18, 19, 31,
  21, 25, 23, 24, 25, 29, 25, 26, 27, 30,
  31, 32, 32};
int aux[] = {
  1, 2, 3, 4, 5, 22, 7, 8, 9, 10,
  20, 12, 13, 14, 15, 28, 17, 18, 19, 31,
  21, 25, 23, 24, 25, 29, 25, 26, 27, 30,
  31, 32, 32};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int dice[10];
  for (int i = 0; i < 10; ++i) cin >> dice[i];
  int ans = 0;
  for (int s = 0; s < (1 << 20); ++s) {
    int sum = 0;
    vector<int> where(4, 0);
    for (int t = 0; t < 10; ++t) {
      int i = (s >> (t << 1)) & 3;
      int v = where[i];
      v = aux[v];
      int rep = dice[t];
      while (--rep) v = nxt[v];
      if (find(where.begin(), where.end(), v) != where.end() && v != 32) break;
      where[i] = v;
      sum += score[v];
    }
    ans = max(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}
