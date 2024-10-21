#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 0;
  int N = 1000;
  int M = 1000;
  cout << T << '\n';
  cout << N << '\n';
  for (int i = 0; i < N; i++) {
    cout << 0 << " \n"[i == N - 1];
  }
  cout << M << '\n';
  for (int i = 0; i < M; i++) {
    cout << 0 << " \n"[i == M - 1];
  }  
  return 0;
}