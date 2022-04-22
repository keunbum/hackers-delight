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
#include <cassert>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) 42
#endif

#define REP(i,n) for (int i = 0; i < (int) (n); i++)
#define REV(i,n) for (int i = ((int) (n)) - 1; i >= 0; i--)
#define TRAV(x,a) for (auto& x : a)

#define N 9

char s[N][N + 1];
bool row[N][N], col[N][N], sqr[N][N];

inline int GetK(int i, int j) { return (i / 3) * 3 + (j / 3); }

void Dfs(int pos) {
  if (pos == N * N) {
    REP(i,N) printf("%s\n", s[i]);
    exit(0);
  }
  int i = pos / N;
  int j = pos % N;
  if (s[i][j] >= '1') {
    Dfs(pos + 1);
    return;
  }
  REP(x,N) {
    if (row[i][x] || col[j][x] || sqr[GetK(i, j)][x]) continue;
    row[i][x] = col[j][x] = sqr[GetK(i, j)][x] = true;
    s[i][j] = (char) (x + '1');
    Dfs(pos + 1);
    row[i][x] = col[j][x] = sqr[GetK(i, j)][x] = false;
  }
  s[i][j] = '0';
}

int main() {
  REP(i,N) {
    scanf("%s", s[i]);
    REP(j,N) {
      int x = (int) (s[i][j] - '0') - 1;
      if (x < 0) continue;
      row[i][x] = col[j][x] = sqr[GetK(i, j)][x] = true;
    }
  }
  Dfs(0);
  assert(false);
  return 0;
}