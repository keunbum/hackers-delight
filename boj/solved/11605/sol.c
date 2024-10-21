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

char cmd[10][10];
int v[10];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%d", cmd[i], v + i);
  }
  int ans = 0;
  for (int x = 1; x <= 100; ++x) {
    int y = x;
    int ok = 1;
    for (int i = 0; i < n; ++i) {
      if (!strcmp(cmd[i], "ADD")) {
        y += v[i];
      }
      if (!strcmp(cmd[i], "SUBTRACT")) {
        y -= v[i];
        ok &= (y >= 0);
      }
      if (!strcmp(cmd[i], "MULTIPLY")) {
        y *= v[i];
      }
      if (!strcmp(cmd[i], "DIVIDE")) {
        ok &= (y % v[i] == 0);
        y /= v[i];
      }
    }
    ans += !ok;
  }
  printf("%d\n", ans);
  return 0;
}