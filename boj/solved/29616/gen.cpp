#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int, char *[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = 100;
  int P = 6;
  cout << N << ' ' << P << '\n';

  int x = (int) 1e8;
  for (int i = 0; i < N - 1; ++i) {
    cout << 1 << ' ';
  }
  cout << (x - (N - 1)) << '\n';

  cout << (x - (N - 1));
  for (int i = 1; i < N; ++i) {
    cout << ' ' << 1;
  }
  cout << '\n';
  return 0;
}