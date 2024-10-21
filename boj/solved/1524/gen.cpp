#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = atoi(argv[1]);
  int MAXN = atoi(argv[2]);
  int MAXF = atoi(argv[3]);
  cout << T << '\n';
  while (T--) {
    cout << '\n';
    int N = rng() % MAXN + 1;
    int M = rng() % MAXN + 1;
    cout << N << ' ' << M << '\n';
    for (int i = 0; i < N; ++i) {
      cout << (rng() % MAXF + 1) << " \n"[i == N - 1];
    }
    for (int i = 0; i < M; ++i) {
      cout << (rng() % MAXF + 1) << " \n"[i == N - 1];
    }
  }
  return 0;
}