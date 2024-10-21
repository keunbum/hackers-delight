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

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

int w, h;
bool was[100][100];
char s[100][101];

int DFS(int i, int j) {
  int ret = 1;
  for (int dir = 0; dir < 4; ++dir) {
    int ni = i + di[dir];
    int nj = j + dj[dir];
    if (ni >= 0 && nj >= 0 && ni < h && nj < w && s[ni][nj] == s[i][j] && !was[ni][nj]) {
      was[ni][nj] = true;
      ret += DFS(ni, nj);
    }
  }
  return ret;
}

int main() {
  scanf("%d%d", &w, &h);
  for (int i = 0; i < h; ++i) {
    scanf("%s", s[i]);
  }
  int ret[2] = {0, 0};
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (!was[i][j]) {
        was[i][j] = true;
        int sz = DFS(i, j);
        ret[s[i][j] == 'B'] += sz * sz;
      }
    }
  }
  printf("%d %d\n", ret[0], ret[1]);
  return 0;
}
