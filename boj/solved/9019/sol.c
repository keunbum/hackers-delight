#include <stdio.h>
#include <string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) 42
#endif

#define MD 10000

int dist[MD];
int que[MD];

int pre[MD];
char chs[MD];

char cmds[MD];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(dist, -1, sizeof(dist));
    int A, B;
    scanf("%d %d", &A, &B);
    que[0] = A;
    dist[A] = 0;
    int b = 0, e = 1;
    while (b < e) {
      int v = que[b];
      int us[4] = {(v + v) % MD, (v + 9999) % MD, (v % 1000) * 10 + v / 1000, (v % 10) * 1000 + v / 10}; 
      for (int id = 0; id < 4; id++) {
        int u = us[id];
        if (dist[u] >= 0) continue;
        dist[u] = dist[v] + 1;
        pre[u] = v;
        chs[u] = "DSLR"[id];
        que[e++] = u;
      }
      ++b;
    }
    int sp = dist[B];
    cmds[sp] = 0;
    while (B != A) {
      cmds[--sp] = chs[B];
      B = pre[B];
    }
    puts(cmds);
  }
  return 0;
}