#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

using tiii = tuple<int, int, int>;

const array<int, 8> di = {-1, -1, 0, 1, 1, 1, 0, -1};
const array<int, 8> dj = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  auto Add = [&](int a, int b) {
    a = (a + b) % n;
    if (a < 0) a += n;
    return a;
  };
  vector<vector<vector<tiii>>> a(n, vector<vector<tiii>>(n));
  while (m--) {
    int x, y, m, s, d;
    cin >> x >> y >> m >> s >> d;
    --x; --y;
    a[x][y].emplace_back(m, s, d);
  }
  while (k--) {
    vector<vector<vector<tiii>>> new_a(n, vector<vector<tiii>>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (auto& e : a[i][j]) {
          auto[m, s, dir] = e;
          int ni = Add(i, s * di[dir]);
          int nj = Add(j, s * dj[dir]);
          new_a[ni][nj].emplace_back(m, s, dir);  
        }
      }
    }
    swap(a, new_a);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j].size() < 2) {
          continue;
        }
        long long sum_m = 0;
        long long sum_s = 0;
        bool allOdd = true;
        bool allEven = true;
        for (auto&[m, s, d] : a[i][j]) {
          sum_m += m;
          sum_s += s;
          allOdd &= (d % 2 == 1);
          allEven &= (d % 2 == 0);
        }
        int new_m = sum_m / 5;
        int new_s = sum_s / (int) a[i][j].size();
        vector<tiii>().swap(a[i][j]);
        if (new_m == 0) {
          continue;
        }
        vector<int> new_dirs;
        if (allOdd || allEven) {
          new_dirs = {0, 2, 4, 6};
        } else {
          new_dirs = {1, 3, 5, 7};
        }
        for (int new_dir : new_dirs) {
          a[i][j].emplace_back(new_m, new_s, new_dir);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (auto& e : a[i][j]) {
        ans += get<0>(e);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * keep calm
  
 * stuff you should look for
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