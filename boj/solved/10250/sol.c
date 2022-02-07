#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) (void) 0
#endif

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);
    --n;
    int i = n / h + 1;
    int j = n % h + 1;
    printf("%d%02d\n", j, i);
  }
  return 0;
}