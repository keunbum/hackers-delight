#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

const int N = 3;

int Encode(int i, int j) { return N * i + j; }

pair<int, int> Decode(int x) { return {x / N, x % N}; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  array<bool, N * N> was{};
  bool ok = true;
  for (int v = 0; v < n - 1; ++v) {
    was[a[v]] = true;
    auto[i, j] = Decode(a[v]);
    auto[ni, nj] = Decode(a[v + 1]);
    ok &= !was[a[v + 1]];
    int di = ni - i;
    int dj = nj - j;
    int s = di * di + dj * dj;
    ok &= !((s == 4 || s == 8) && !was[Encode(i + di / 2, j + dj / 2)]);
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  
 * stuff you should look for
  * 0-based or 1-based?
  * off-by-one error
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/