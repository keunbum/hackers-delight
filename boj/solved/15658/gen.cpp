#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = 11;
  cout << N << '\n';
  const int MAX = 100;
  for (int i = 0; i < N; i++) {
    cout << rng() % MAX + 1 << " \n"[i == N - 1];
  }
  cout << 11 << " " << 11 << " " << 11 << " " << 11;
  return 0;
}