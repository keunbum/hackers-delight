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
  constexpr int N = 9;
  auto GetK = [&](int i, int j) { return (i / 3) * 3 + (j / 3); };
  vector<string> s(N);
  vector<vector<bool>> row(N, vector<bool>(N, false));
  vector<vector<bool>> col(N, vector<bool>(N, false));
  vector<vector<bool>> sqr(N, vector<bool>(N, false));
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    for (int j = 0; j < N; j++) {
      int x = (int) (s[i][j] - '0');
      x -= 1;
      if (x == -1) {
        continue;
      }
      row[i][x] = col[j][x] = sqr[GetK(i, j)][x] = true;
    }
  }
  function<void(int)> Dfs = [&](int pos) {
    if (pos == N * N) {
      for (int x = 0; x < N; x++) {
        cout << s[x] << '\n';
      }
      exit(0);
    }          
    auto[i, j] = make_pair(pos / N, pos % N);
    if (s[i][j] >= '1') {
      Dfs(pos + 1);
      return;
    }
    int k = GetK(i, j);     
    for (int x = 0; x < N; x++) {
      if (row[i][x] || col[j][x] || sqr[k][x]) {
        continue;
      }
      row[i][x] = col[j][x] = sqr[k][x] = true;
      s[i][j] = (char) (x + '1');
      Dfs(pos + 1);
      row[i][x] = col[j][x] = sqr[k][x] = false;
    }
    s[i][j] = '0';
  };
  Dfs(0);
  assert(false);
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