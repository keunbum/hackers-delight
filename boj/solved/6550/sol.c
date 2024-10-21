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

#define N ((int) 1e5 + 1)

char s[N], t[N];

int main() {
  while (~scanf("%s %s", s, t)) {
    int i = 0;
    int ok = 0;
    int ns = strlen(s);
    for (int j = 0; t[j]; ++j) {
      if (t[j] == s[i]) {
        if (++i == ns) {
          ok = 1;
          break;
        }
      }
    }
    puts(ok ? "Yes" : "No");
  }
  return 0;
}