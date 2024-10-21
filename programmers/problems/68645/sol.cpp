#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(int n) {
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(i + 1);
  }
  int cnt = 0;
  int i = 0;
  int j = 0;
  int di = 1;
  int dj = 0;
  while (cnt < n * (n + 1) / 2) {
    a[i][j] = ++cnt;
    int ni = i + di;
    int nj = j + dj;
    if (ni < 0 || nj < 0 || nj > ni || ni >= n || a[ni][nj] != 0) {
      di = (di + 3) % 3 - 1;
      dj = (dj + 2) % 3 - 1;
      ni = i + di;
      nj = j + dj;
    }
    i = ni;
    j = nj;
  }
  vector<int> ret;
  for (auto& row : a) {
    ret.insert(ret.end(), row.begin(), row.end());
  }
  debug(ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i < 10; i++) {
    solution(i);
  }
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