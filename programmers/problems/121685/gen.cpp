#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = 5;
  cout << N << '\n';
  for (int i = 0; i < N; i++) {
    int M = (1 << (i + i));
    cout << (i + i) << '\n';
    for (int j = 0; j < M; j++) {
      cout << (i + 1) << " " << (j + 1) << '\n';
    }
  }
  return 0;
}