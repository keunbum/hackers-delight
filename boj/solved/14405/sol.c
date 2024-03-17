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

int Find(const char* s, int l, const char* t) {
  for (int i = 0; i < l; ++i) {
    if (s[i] != t[i]) {
      return 0;
    }
  }
  return 1;
}

const char* S[3] = {"pi", "ka", "chu"};
char s[5001];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int i = 0;
  while (i < n) {
    int ok = 0;
    for (int j = 0; j < 3; ++j) {
      int sz = strlen(S[j]);
      if (Find(s + i, sz, S[j])) {
        ok = 1;
        i += sz;
        break;
      }
    }
    if (!ok) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}