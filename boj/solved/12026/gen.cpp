#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = rng() % 300 + 1;
  string s(N, ' ');
  s[0] = 'B';
  for (int i = 1; i < N; i++) {
    s[i] = "BOJ"[rng() % 3];
  }
  cout << N << '\n';
  cout << s << '\n';
  return 0;
}