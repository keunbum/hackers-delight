#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  assert(argc == 2);
  double P = atof(argv[1]);
  for (int N = 0; N <= (int) 1e9; ++N) {
    double q = (10LL * N + 5) / P;
    if ((long long) q % 10 == 5) {
      double t = 10 * N + 5 / P;
      if (t == (int) (100 * t) / 100.0) {
        debug(N, t);
        return 0;
      }
    }
  }
  assert(false);
  return 0;
}
