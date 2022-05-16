#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W, R;
  cin >> H >> W >> R;
  vector<vector<int>> a(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }
  for (int base = 0; base < min(H, W) / 2; base++) {
    int h = H - 2 * base;
    int w = W - 2 * base;
    int n = (h + w) * 2 - 4;
    debug(base, h, w, n);
    vector<int> v(n);
    {
      int ptr = 0;
      for (int j = 0; j < w - 1; j++) {
        v[ptr++] = a[base][base + j];
      }
      for (int i = 0; i < h - 1; i++) {
        v[ptr++] = a[base + i][base + w - 1];
      }
      for (int j = w - 1; j > 0; j--) {
        v[ptr++] = a[base + h - 1][base + j];
      }
      for (int i = h - 1; i > 0; i--) {
        v[ptr++] = a[base + i][base];
      }
      debug(ptr);
      assert(ptr == n);
    }
    debug(v);
    int r = R % n;
    rotate(v.begin(), v.begin() + r, v.end());
    {
      int ptr = 0;
      for (int j = 0; j < w - 1; j++) {
        a[base][base + j] = v[ptr++];
      }
      for (int i = 0; i < h - 1; i++) {
        a[base + i][base + w - 1] = v[ptr++];
      }
      for (int j = w - 1; j > 0; j--) {
        a[base + h - 1][base + j] = v[ptr++];
      }
      for (int i = h - 1; i > 0; i--) {
        a[base + i][base] = v[ptr++];
      }
    }
    debug(a);
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << a[i][j] << " \n"[j == W - 1];
    }
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
  * 0-based or 1-based?
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/