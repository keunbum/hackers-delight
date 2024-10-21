#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  assert(argc == 4);
  int P = atoi(argv[1]);
  int Q = atoi(argv[2]);
  int N = atoi(argv[3]);
  cout << N << '\n';
  while (N--) {
    int T = (rng() % Q);                              
    cout << (rng() % (P + 1)) << "." << (0 <= T && T < 10 ? "0" : "" + to_string(T)) << " " << "RGBYOW"[rng() % 6] << " " << "CX"[rng() % 2] << " " << "CP"[rng() % 2] << '\n';
  }
  return 0;
}