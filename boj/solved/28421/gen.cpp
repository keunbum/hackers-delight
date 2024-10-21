#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  assert(argc == 3);
  int N = atoi(argv[1]);
  int Q = atoi(argv[2]);
  cout << N << ' ' << Q << '\n';
  vector<int> a(N);
  const int MAX = (int) 1e4;
  const int MAXX = (int) 1e8;
  for (int i = 0; i < N; ++i) {
    a[i] = rng() % MAX + 1;
    cout << a[i] << " \n"[i == N - 1];
  }
  while (Q--) {
    int c = rng() % 2 + 1;
    cout << c << ' ';
    if (c == 1) {
      cout << (rng() % (MAXX + 1)) << '\n';
    } else {
      cout << (rng() % N + 1) << '\n';
    }
  }
  return 0;
}