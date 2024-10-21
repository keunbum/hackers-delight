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
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int w, h;
    scanf("%d%d", &w, &h);
    char s[32];
    memset(s, 'X', w);
    s[w] = '\0';
    while (h--) {
      puts(s);
    }
    puts("");
  }
  return 0;
}