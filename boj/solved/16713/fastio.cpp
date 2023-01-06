/* Note that it does not run normally on Windows. */
#include <bits/stdc++.h>

using namespace std;

#define BUF_SIZE 1 << 17

char buf[BUF_SIZE];
char readchar() {
  static int pos = 0, reads = 0;
  if (pos >= reads) {
    reads = fread(buf, 1, BUF_SIZE, stdin);
    pos = 0;
  }
  return buf[pos++];
}

int readint() {
  char ch = readchar();
  int x = 0;
  while (ch > ' ') {
    x = x * 10 + ch - '0';
    ch = readchar();
  }
  return x;
}

int n, q, s, e, ans;
int sum[(int)1e6 + 1];
int main() {
  n = readint();
  q = readint();
  for (int i = 0; i < n; i++) {
    sum[i + 1] = readint() ^ sum[i];
  }
  while (q--) {
    ans ^= sum[readint() - 1] ^ sum[readint()];
  }
  return !printf("%d\n", ans);
}