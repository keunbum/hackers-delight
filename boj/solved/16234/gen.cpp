#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 100;
  const int N = 50;
  int L;
  int R;
  do {
    L = rng() % MAX + 1;
    R = rng() % MAX + 1;
  } while (L > R);
  cout << N << " " << L << " " << R << '\n';
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j > 0) {
        cout << " ";
      }
      cout << rng() % (MAX + 1);
    }
    cout << '\n';
  }
  return 0;
}