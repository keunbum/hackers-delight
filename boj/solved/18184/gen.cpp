#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = rng() % 12 + 1;
  cout << N << " " << (rng() % (1 << N) + 1) << '\n';
  return 0;
}