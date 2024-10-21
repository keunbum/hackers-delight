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

int compare(const void *p, const void *q) {
  return *((int *) p) - *((int *) q);
}

int a[(int) 1e6];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  qsort(a, n, sizeof(a[0]), compare);
  for (int i = 0; i < n; i++) {
    printf("%d\n", a[i]);
  }
  return 0;
}
