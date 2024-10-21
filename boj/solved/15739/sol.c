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

#define N (100)

int a[N][N];
bool used[N * N];

int main() {
  int n;
  scanf("%d", &n);
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i] + j);
      ok &= !used[a[i][j] - 1];
      used[a[i][j] - 1] = true;
    }
  }
  int s = n * (n * n + 1) / 2;
  for (int rot = 0; rot < 2; ++rot) {
    for (int i = 0; i < n; ++i) {
      int c = 0;
      for (int j = 0; j < n; ++j) {
        c += (rot == 0 ? a[i][j] : a[j][i]);
      }
      ok &= (c == s);
    }
  }
  for (int rot = 0; rot < 2; ++rot) {
    int c = 0;
    for (int i = 0; i < n; ++i) {
      c += (rot == 0 ? a[i][i] : a[i][n - 1 - i]);
    }
    ok &= (c == s);
  }
  puts(ok ? "TRUE" : "FALSE");
  return 0;
}