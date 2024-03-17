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

#define max(a, b) a > b ? a : b

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  int max_v = 0;
  int max_c = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x > max_v) {
      max_v = x;
      max_c = 0;
    } else {
      max_c += 1;
    }
    ans = max(ans, max_c);
  }
  printf("%d\n", ans);
  return 0;
}