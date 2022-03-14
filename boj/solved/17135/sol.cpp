#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int inf = (int) 1e8;
  int h, w, d;
  cin >> h >> w >> d;
  vector<vector<bool>> a(h, vector<bool>(w, false));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int x;
      cin >> x;
      a[i][j] = x;
    }
  }
  vector<int> v;
  int ans = 0;
  function<void(int)> Dfs = [&](int pos) {
    if ((int) v.size() == 3) {
      vector<vector<bool>> g(a);
      int cur = 0;
      for (int rot = 0; rot < h; rot++) { 
        set<pair<int, int>> s;
        for (int id : v) {
          int min_d = inf;
          int mi, mj;
          for (int j = 0; j < w; j++) {
            for (int i = h - 1 - rot; i >= 0; i--) {
              if (g[i][j] == 0) {
                continue;
              }
              int dis = h - rot - i + abs(id - j);
              if (dis <= d && dis < min_d) {
                min_d = dis;
                mi = i;
                mj = j;
              }
            }
          }
          if (min_d < inf) {
            s.emplace(mi, mj);
          }
        }
        for (auto[x, y] : s) {
          g[x][y] = 0;
        }
        cur += s.size();
      }
      ans = max(ans, cur);
      return;
    }
    for (int j = pos; j < w; j++) {
      v.push_back(j);
      Dfs(j + 1);
      v.pop_back();
    }
  };
  Dfs(0);
  cout << ans << '\n';
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