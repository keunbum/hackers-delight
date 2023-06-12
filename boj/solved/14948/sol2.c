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

#define H (100)
#define W (100)
#define QUE_MAX_SZ (H * W * 2)
#define UNIT_INF (0x3f)

#define MAX(x, y) x > y ? x : y
#define MIN(x, y) x < y ? x : y

typedef struct {
  int x, y;
} Pair;

void Swap(Pair* pi, Pair* pj) {
  Pair temp = *pi;
  *pi = *pj;
  *pj = temp;
}

int Comp(Pair pi, Pair pj) {
  return pi.x > pj.x;
}

size_t pq_n;
Pair tree[QUE_MAX_SZ];

int IsEmpty() { return pq_n == 0; }
Pair GetTop() { return tree[0]; }
void Init() { pq_n = 0; }

// [0, i)
void UpHeap(int i) {
  --i;
  int pr;
  while (i > 0 && Comp(tree[pr = (i - 1) >> 1], tree[i])) {
    Swap(&tree[pr], &tree[i]); 
    i = pr;
  }
}

void Push(Pair val) {
  tree[pq_n++] = val;
  UpHeap(pq_n);
} 

// [i, e)
void DownHeap(int i, int e) {
  while (1) {
    int l = (i << 1) | 1;
    int r = l + 1;
    int j = i;
    if (l < e && Comp(tree[j], tree[l])) j = l;
    if (r < e && Comp(tree[j], tree[r])) j = r;
    if (i == j) break;
    Swap(&tree[j], &tree[i]);
    i = j;
  }
}

Pair Pop() {    
  Swap(&tree[0], &tree[pq_n - 1]);
  DownHeap(0, --pq_n);
  return tree[pq_n];
}

int h, w;

int Encode(int i, int j, int jump) {
  return ((w * i + j) << 1) | jump;
}

void Decode(int x, int* i, int* j, int* jump) {
  int y = x >> 1;
  *i = y / w;
  *j = y % w;
  *jump = x & 1;
}

int a[H][W];
int dist[QUE_MAX_SZ]; 

int main() {
  int i, j, st, expected, v, mi, mj, jump, dir, t, ni, nj, u, mx;
  scanf("%d %d", &h, &w);
  for (i = 0; i < h; ++i) for (j = 0; j < w; ++j) scanf("%d", a[i] + j);
  Init();
  memset(dist, UNIT_INF, sizeof(dist));
  st = Encode(0, 0, 1);
  dist[st] = a[0][0];
  Push((Pair) {dist[st], st});
  while (!IsEmpty()) {
    expected = GetTop().x;
    v = GetTop().y;
    Pop();
    if (expected != dist[v]) continue;
    Decode(v, &mi, &mj, &jump);
    for (dir = 0; dir < 4; ++dir) for (t = 1; t <= jump + 1; ++t) {
      ni = mi + t * ("2101"[dir] - '1');
      nj = mj + t * ("1210"[dir] - '1');
      u = Encode(ni, nj, jump - (t - 1));
      if (ni >= 0 && ni < h && nj >= 0 && nj < w && dist[u] > (mx = MAX(dist[v], a[ni][nj]))) {
        dist[u] = mx;
        Push((Pair) {dist[u], u});
      }
    }
  }
  printf("%d\n", MIN(dist[Encode(h - 1, w - 1, 0)], dist[Encode(h - 1, w - 1, 1)]));
  return 0;
}
