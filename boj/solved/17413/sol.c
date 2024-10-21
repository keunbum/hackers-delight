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

#define N 100010

char s[N], cur[N];

int main() {
  fgets(s, N, stdin);
  int i;
  int sp = 0;
  int cp = 0;
  int balance = 0;
  for (i = 0; s[i]; i++) {
    char ch = s[i];
    if (balance > 0) {
      if (ch == '>') {
        balance -= 1;
      }
      goto PUSH;
    }
    if (isalnum(ch)) {
      cur[cp++] = ch;
      goto END;
    }
    if (ch == '<') {
      balance += 1;
    }
    while (cp > 0) {
      s[sp++] = cur[--cp];
    }
PUSH:
    s[sp++] = ch;
END:
  }
  while (cp > 0) {
    s[sp++] = cur[--cp];
  }
  assert(sp == i);
  puts(s);
  return 0;
}