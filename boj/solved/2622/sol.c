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
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int x = 1; x + x < n; ++x) {
    int s = n - x;
    if (x >= (s + 1) / 2) {
      ans += s / 2 - (s - x - 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}