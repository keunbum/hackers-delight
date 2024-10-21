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

char s[500][502];

int main() {
  int h, w;
  scanf("%d%d\n", &h, &w);
  for (int i = 0; i < h; ++i) {
    fgets(s[i], 502, stdin);
    s[i][w] = '\0';
    for (int j = 0; j < w; ++j) {
      if (s[i][j] == '.') {
        s[i][j] = 'D';
      }
    }
  }
  bool ok = true;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (j + 1 < w) {
        ok &= (s[i][j] != 'W' || s[i][j + 1] != 'S');
        ok &= (s[i][j] != 'S' || s[i][j + 1] != 'W');
      }
      if (i + 1 < h) {
        ok &= (s[i][j] != 'W' || s[i + 1][j] != 'S');
        ok &= (s[i][j] != 'S' || s[i + 1][j] != 'W');
      }
    }
  }
  if (!ok) {
    puts("0");
    return 0;
  }
  puts("1");
  for (int i = 0; i < h; ++i) {
    puts(s[i]);
  }
  return 0;
}