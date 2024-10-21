#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 1000;
  cout << N << '\n';
  for (int i = 1; i <= N; i++) {
    if (i > 1) {
      cout << " ";
    }
    cout << i;
  }
  return 0;
}