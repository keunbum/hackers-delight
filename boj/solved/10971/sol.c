#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) (void) 0
#endif

#define N (10)

int min(int a, int b) { return a < b ? a : b; }

int ans, n, used;
int a[N][N];

void DFS(int v, int cost) {
  if (used == (1 << n) - 1) {
    if (a[v][n - 1] != 0) {
      ans = min(ans, cost + a[v][n - 1]);
    }
    return;
  }
  for (int u = 0; u < n - 1; ++u) {
    if (!((used >> u) & 1) && a[v][u] != 0) {
      used |= 1 << u;
      DFS(u, cost + a[v][u]);
      used &= ~(1 << u);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i] + j);
    }
  }
  ans = (int) 1e8;
  used = 1 << (n - 1);
  DFS(n - 1, 0);
  printf("%d\n", ans);
  return 0;
}
