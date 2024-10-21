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

enum {
  N = (int) 1e6
};

typedef struct Pair Pair;
struct Pair {
  int x;
  int y;
};

void Swap(Pair *a, Pair *b) {
  Pair t = *b;
  *b = *a;
  *a = t;
}

void SSort(Pair *a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i].x > a[j].x) {
        Swap(a + i, a + j);
      }
    }
  }
}

void QSort(Pair *a, int n) {
  if (n < 16) {
    SSort(a, n);
    return;
  }   
  int pi = a[rand() % n].x;
  int L = 0;
  int R = n - 1;
  while (1) {
    while (a[L].x < pi) ++L;
    while (a[R].x > pi) --R;
    if (L >= R) {
      break;
    }
    Swap(a + L, a + R);
    ++L;
    --R;
  }
  QSort(a, L);
  QSort(a + L, n - L);
}

int a[N];
Pair b[N];

int main() {
  srand(time(0));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    b[i].x = a[i];
    b[i].y = i;
  }
  QSort(b, n);
  int t = 0;
  a[b[0].y] = 0;
  for (int i = 1; i < n ; i++) {
    t += (b[i].x > b[i - 1].x);
    a[b[i].y] = t;
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", a[i], i < n - 1 ? ' ' : '\n');
  }
  return 0;
}