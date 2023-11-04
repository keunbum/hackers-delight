#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto Encode = [&](int x, int y) {
    return 1LL * n * x + y;
  };
  vector<long long> a(k);
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    a[i] = Encode(x, y);
  }
  sort(a.begin(), a.end());
  vector<long long> b;
  for (int i = 0; i < k; ++i) {
    for (int di = -2; di <= 2; ++di) {
      for (int dj = -2; dj <= 2; ++dj) {
        if (di * di + dj * dj == 4) {
          int nx = a[i] / n + di;
          int ny = a[i] % n + dj;
          long long nz = Encode(nx, ny);
          if (min(nx, ny) >= 0 && max(nx, ny) < n && !binary_search(a.begin(), a.end(), nz)) {
            b.push_back(nz);
          }
        }
      }
    }
  }
  sort(b.begin(), b.end());
  cout << (unique(b.begin(), b.end()) - b.begin()) << '\n';
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