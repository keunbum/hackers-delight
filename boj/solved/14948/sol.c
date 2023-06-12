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

int h, w;

int Encode(int i, int j, int k) {
  return ((w * i + j) << 1) | k;
}

void Decode(int x, int* i, int* j, int* k) {
  int y = x >> 1;
  *i = y / w;
  *j = y % w;
  *k = x & 1;
}

#define H 100
#define W 100

int a[H][W];
int que[H * W * 2];
char was[H * W * 2];

int main() {
  int i, j, k, low, high, mid, st, b, e, ni, nj, nk, u, t, dir;
  scanf("%d %d", &h, &w);
  high = -1;
  for (i = 0; i < h; ++i) for (j = 0; j < w; ++j) {
    scanf("%d", a[i] + j);
    if (a[i][j] > high) high = a[i][j];
  }
  low = a[0][0];
  while (low < high) {
    mid = (low + high) >> 1;
    st = Encode(0, 0, 1);
    que[0] = st;
    memset(was, 0, sizeof(was));
    was[st] = 1;
    e = 1;
    for (b = 0; b < e; ++b) {
      Decode(que[b], &i, &j, &k);
      for (dir = 0; dir < 4; ++dir) {
        for (t = 1; t <= k + 1; ++t) {
          ni = i + t * ("2101"[dir] - '1');
          nj = j + t * ("1210"[dir] - '1');
          nk = k + - (t - 1);
          u = Encode(ni, nj, nk);
          if (ni >= 0 && ni < h && nj >= 0 && nj < w && !was[u] && a[ni][nj] <= mid) {
            was[u] = 1;
            que[e++] = u;
          }
        }
      }
    }
    if (was[Encode(h - 1, w - 1, 0)] || was[Encode(h - 1, w - 1, 1)]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  printf("%d\n", low);
  return 0;
}
