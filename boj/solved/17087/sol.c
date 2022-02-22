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

int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }

int GCD2(int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main() {
  int N, S, D;
  scanf("%d %d %d", &N, &S, &D);
  D -= S;
  while (--N) {
    int x;
    scanf("%d", &x);
    D = GCD2(D, x - S);
  }
  printf("%d\n", abs(D));
  return 0;
}
