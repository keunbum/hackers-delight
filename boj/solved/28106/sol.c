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

#define N (int)2e3
#define md (998244353)

void Add(int* a, int b) {
  *a += b;
  if (*a >= md) *a -= md;
}

int top;
int a[N], to[N], last[N], pre[N], dp[N], depth[N], stk[N];

void DFS(int v) {
  int id = last[v];
  if (id == -1) {
    dp[v] = 1;
    return;
  }
  stk[top++] = v;
  while (~id) {
    int u = to[id];
    depth[u] = depth[v] + 1;
    DFS(u);
    for (int ptr = 0; ptr < top; ++ptr) {
      int anc = stk[ptr];
      if (depth[u] - depth[anc] <= a[anc]) {
        Add(dp + anc, dp[u]);
      }
    }
    id = pre[id];
  }
  --top;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    last[i] = -1;
  }
  int root = -1;
  for (int id = 0; id < n; ++id) {
    int p;
    scanf("%d", &p);
    --p;
    int c = id;
    if (p != -1) {
      to[id] = c;
      pre[id] = last[p];
      last[p] = id;
    } else {
      root = c;
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  depth[root] = 0;
  DFS(root);
  printf("%d\n", dp[root]);
  return 0;
}
