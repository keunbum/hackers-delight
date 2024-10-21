#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int R = 10;
  int C = 10;
  int T = 10;
  cout << R << " " << C << " " << T << '\n';
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      int x = rng() % 1000;
      if ((i == 2 && j == 0) || (i == 3 && j == 0)) {
        x = -1;
      }
      cout << x << " \n"[j == C - 1];
    }
  }
  return 0;
}