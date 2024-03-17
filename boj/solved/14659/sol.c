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

#define max(x, y) x > y ? x : y

int a[30010];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int j = i + 1;
    while (j < n && a[i] > a[j]) {
      j += 1;
    }
    ans = max(ans, j - i);
  }
  printf("%d\n", ans - 1);
  return 0;
}