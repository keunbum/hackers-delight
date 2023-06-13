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

void Swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void DownHeap(int* a, int n) {
  int i = 0;
  while (1) {
    int l = i << 1 | 1;
    int r = l + 1;
    int j = i;
    if (l < n && a[j] < a[l]) j = l;
    if (r < n && a[j] < a[r]) j = r;
    if (i == j) break;
    Swap(a + j, a + i);
    i = j;
  }
}

void Sort(int* a, int n) {
  for (int i = (n - 1) >> 1; i >= 0; --i) DownHeap(a + i, n - i);
  for (int i = n - 1; i > 0; --i) {
    Swap(a, a + i);
    DownHeap(a, i);
  }
}

int BinarySearch(int* a, int n, int v) {
  int low = 0;
  int high = n - 1;
  while (low < high) {
    int mid = (low + high) >> 1;
    if (v > a[mid]) {
      low = mid + 1;
    } else {
      high = mid;
    }
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
