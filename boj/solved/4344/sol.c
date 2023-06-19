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
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int a[1000];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      sum += a[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += (a[i] * n > sum);
    }
    double avr = ((int) ((1.0 * cnt / n + 5e-6) * 1e5)) / 1e3;
    printf("%.3lf%%\n", avr);
  }
  return 0;
}
