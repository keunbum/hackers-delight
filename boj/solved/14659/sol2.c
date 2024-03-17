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

int a[30010];
short stk[30010];

int main() {
  int n;
  scanf("%d", &n);
  int sp = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    while (sp > 0 && a[stk[sp - 1]] < a[i]) {
      ans = max(ans, i - stk[sp - 1] - 1);
      sp -= 1;
    }
    stk[sp++] = i;
  }
  while (sp > 0) {
    ans = max(ans, n - stk[sp - 1] - 1);
    sp -= 1;
  }
  printf("%d\n", ans);
  return 0;
}