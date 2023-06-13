#include <cstdio>
#include <algorithm>

using namespace std;

int a[5000];

int main() {
  int N, C;
  scanf("%d %d", &N, &C);
  bool ok = false;
  for (int i = 0; i < N; ++i) {
    scanf("%d", a + i);
    ok |= (a[i] == C);
  }
  sort(a, a + N);
  int L = 0;
  int R = N - 1;
  while (L < R) {
    int v = C - (a[L] + a[R]);
    if (v < 0) {
      R -= 1;
    } else {
      ok |= (v == 0 || (v != a[L] && v != a[R] && binary_search(a, a + N, v)));
      L += 1;
    }
  }
  return !printf("%d\n", ok);
}