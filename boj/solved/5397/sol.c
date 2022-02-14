#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#define MAX 1000010

char s[MAX];

char stkA[MAX], stkB[MAX];

int main() {
  int T;
  scanf("%d\n", &T);
  while (T--) {
    fgets(s, MAX, stdin);
    int topA = 0;
    int topB = MAX - 3;
    for (int i = 0; s[i] != '\n' && s[i]; i++) {
      if (s[i] == '-') {
        if (topA > 0) --topA;
      }
      if (s[i] == '<') {
        if (topA > 0) stkB[topB--] = stkA[--topA];
      }
      if (s[i] == '>') {
        if (topB < MAX - 3) stkA[topA++] = stkB[++topB];
      }
      if (isalnum((int) s[i])) {
        stkA[topA++] = s[i];
      }
    }
    stkB[MAX - 2] = '\n';
    stkA[topA] = stkB[MAX - 1] = 0;
    fputs(stkA, stdout);
    fputs(stkB + topB + 1, stdout);
  }
  return 0;
}