#include <stdbool.h>
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

int Cmp(const void* p, const void* q) {
  return *(const int*) p - *(const int*) q;
}

#define N (20000)
#define M (20000)

int a[N], b[M];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < m; ++i) scanf("%d", b + i);
    qsort(b, m, sizeof(b[0]), Cmp);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int low = 0;
      int high = m;
      while (low < high) {
        int mid = (low + high) >> 1;
        if (a[i] > b[mid]) low = mid + 1;
        else high = mid;
      }
      ans += high;
    }
    printf("%d\n", ans);
  }
  return 0;
}