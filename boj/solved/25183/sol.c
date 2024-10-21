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
  int n;
  static char s[100001];
  scanf("%d %s", &n, s);
  for (int i = 0; i <= n - 5; ++i) {
    int ok = 1;
    for (int j = i; j < i + 4; ++j) {
      ok &= abs(s[j] - s[j + 1]) == 1;
    }
    if (ok) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}