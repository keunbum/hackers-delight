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

int main() {
  int d, vf, vg;
  int da2 = 144;
  while (~scanf("%d%d%d", &d, &vf, &vg)) {
    int db2 = da2 + d * d;
    printf("%c\n", "NS"[da2 * vg * vg >= db2 * vf * vf]);
  }
  return 0;
}