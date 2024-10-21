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

int a[101][101];
int qx[10000], qy[10000];

int main() {
  int h, w;
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      scanf("%1d", a[i] + j);
    }
  }
  for (int b = 0, e = 1; b < e; ++b) {
    for (int dir = 0; dir < 4; ++dir) {
      int nx = qx[b] + "2101"[dir] - '1';
      int ny = qy[b] + "1210"[dir] - '1';
      if (nx >= 0 && ny >= 0 && nx < h && ny < w && a[nx][ny] == 1) {
        a[nx][ny] = a[qx[b]][qy[b]] + 1;
        qx[e] = nx;
        qy[e++] = ny;
      }
    }
  }
  printf("%d", a[h - 1][w - 1]);
  return 0;
}
