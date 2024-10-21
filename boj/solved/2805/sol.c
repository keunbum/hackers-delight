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

#define N ((int) 1e6)

int max(int a, int b) { return a > b ? a : b; }

int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int low = 0;
  int high = (int) 1e9;
  while (low < high) {
    int mid = low + (high - low + 1) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += max(a[i] - mid, 0);
    }
    if (sum >= m) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  printf("%d\n", low);
  return 0;
}
