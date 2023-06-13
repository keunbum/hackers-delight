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

#define N (5000)

void Sort(int* a, int L) {
  static int cache[N];
  if (L <= 1) {
    return;
  }
  int n = L / 2;
  int* b = a + n;
  int m = L - n;
  Sort(a, n);
  Sort(b, m);
  int i = 0, j = 0, k = 0;
  while (i < n && j < m) cache[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
  while (i < n) cache[k++] = a[i++];
  for (i = 0; i < k; ++i) a[i] = cache[i];
}

int BinarySearch(int* a, int n, int v) {
  int low = 0;
  int high = n - 1;
  while (low < high) {
    int mid = (low + high) >> 1;
    if (v > a[mid]) low = mid + 1;
    else high = mid;
  }
  return a[low] == v;
}

int a[N];

int main() {
  int n, c;
  scanf("%d %d", &n, &c);
  int ok = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    ok |= (a[i] == c);
  }
  Sort(a, n);
  int L = 0;
  int R = n - 1;
  while (L < R) {
    int v = c - (a[L] + a[R]);
    if (v < 0) R -= 1;
    else {
      ok |= (v == 0 || (v != a[L] && v != a[R] && BinarySearch(a, n, v)));
      L += 1;
    }
  }
  return !printf("%d\n", ok);
}
