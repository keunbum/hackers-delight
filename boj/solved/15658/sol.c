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

#define N 11
#define INF (int) 2e9

int a[N];

int n;

int max = -INF;
int min = INF;

void Dfs(int v, int c, int x, int y, int z, int w) {
  if (v == n - 1) {
    if (c > max) max = c;
    if (c < min) min = c;
    return;
  }
  if (x > 0) Dfs(v + 1, c + a[v + 1], x - 1, y, z, w);
  if (y > 0) Dfs(v + 1, c - a[v + 1], x, y - 1, z, w);
  if (z > 0) Dfs(v + 1, c * a[v + 1], x, y, z - 1, w);
  if (w > 0) Dfs(v + 1, c / a[v + 1], x, y, z, w - 1);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int x, y, z, w;
  scanf("%d %d %d %d", &x, &y, &z, &w);
  Dfs(0, a[0], x, y, z, w);
  printf("%d\n%d\n", max, min);
  return 0;
}
