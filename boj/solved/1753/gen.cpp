#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int W = 10;
  int V, E;
  if (argc == 3) {
    V = atoi(argv[1]);
    E = atoi(argv[2]);
  } else {
    V = 2;
    E = 3;
  }
  int K = rng() % V + 1;
  while (E--) {
    int x, y;
    do {
      x = rng() % V + 1;
      y = rng() % V + 1;
    } while ();
  }
  return 0;
}