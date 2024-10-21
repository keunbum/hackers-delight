#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 5;
  string s = "";
  for (int i = 0; i < N; i++) {
    s += (char) (rng() % 26 + 'a');
  }
  cout << s << '\n';
  const int M = 10;
  cout << M << '\n';
  for (int _ = 0; _ < M; _++) {
    char ch = "LDBP"[rng() % 4];
    cout << ch;
    if (ch == 'P') {
      cout << " " << (char) (rng() % 26 + 'a');
    }
    cout << '\n';
  }
  return 0;
}