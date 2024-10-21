#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  assert(argc == 4);
  int H = atoi(argv[1]);
  int W = atoi(argv[2]);
  int M = atoi(argv[3]);
  assert(M <= H * W);
  cout << H << ' ' << W << ' ' << M << '\n';
  vector<int> sizes(M);
  iota(sizes.begin(), sizes.end(), (int)1e4 - M + 1);
  set<pair<int, int>> pos;
  for (int i = 0; i < M; ++i) {
    int r, c;
    do {
      r = rng() % H + 1;
      c = rng() % W + 1;
    } while (!pos.emplace(r, c).second);
    int s = rng() % 1 + 1000;
    int d = rng() % 4 + 1;
    int z = sizes[i];
    cout << r << ' ' << c << ' ' << s << ' ' << d << ' ' << z << '\n';
  }
  return 0;
}