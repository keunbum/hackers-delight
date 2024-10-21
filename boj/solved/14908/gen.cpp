#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = atoi(argv[1]);
  int MAXT = atoi(argv[2]);
  int MAXS = atoi(argv[3]);
  cout << N << '\n';
  while (N--) {
    int t = rng() % MAXT + 1;
    int s = rng() % MAXS + 1;
    cout << t << ' ' << s << '\n';
  }
  return 0;
}