#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <chrono>
#include <random>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) 42
#endif

#define REP(i,n) for (int i = 0; i < (int) (n); i++)
#define REV(i,n) for (int i = ((int) (n)) - 1; i >= 0; i--)
#define TRAV(x,a) for (auto& x : a)

#define N 1001

short C[N][N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i <= n; i++) C[i][0] = C[i][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 10007;
    }
  }
  printf("%d\n", C[n][k]);
  return 0;
}