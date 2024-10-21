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

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    char s[21];
    scanf("%s", s);
    int i;
    int upper = 0, lower = 0;
    int notdigit = 0;
    for (i = 0; s[i]; ++i) {
      upper += 'A' <= s[i] && s[i] <= 'Z';
      lower += 'a' <= s[i] && s[i] <= 'z';
      notdigit |= !('0' <= s[i] && s[i] <= '9');
    }
    if (upper <= lower && i <= 10 && notdigit) {
      puts(s);
      return 0;
    }
  }
  assert(0);
  return 0;
}
