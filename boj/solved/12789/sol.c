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

int stk[1234];

int main() {
  int n;
  scanf("%d", &n);
  int top = 0;
  int cnt = 0;
  while (n--) {
    int x;
    scanf("%d", &x);
    while (top > 0 && stk[top - 1] < x) {
      if (cnt + 1 != stk[top - 1]) {
        puts("Sad");
        return 0;
      }
      cnt += 1;
      top -= 1;
    }
    stk[top++] = x;
  }
  puts("Nice");
  return 0;
}