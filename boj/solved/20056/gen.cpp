#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int MAX = 10;
  int N = 5;
  int M = 3;
  int K = 5;
  cout << N << " " << M << " " << K << '\n';
  set<pair<int, int>> s;
  while (M--) {
    int i, j;
    while (true) {
      i = rng() % N + 1;
      j = rng() % N + 1;
      if ((s.emplace(i, j).second)) {
        break;
      }
    }
    int m = rng() % MAX + 1;
    int s = rng() % MAX + 1;
    int d = rng() % 8;
    cout << i << " " << j << " " << m << " " << s << " " << d << '\n';
  }
  return 0;
}