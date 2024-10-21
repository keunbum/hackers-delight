#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 20;
  cout << N << '\n';
  for (int i = 0; i < N; i++) {
    string s;
    for (int j = 0; j < N; j++) {
      s += "HT"[rng() % 2];
    }
    cout << s << '\n';
  }
  return 0;
}