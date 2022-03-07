#include <bits/stdc++.h>

using namespace std;

pair<int, int> F(int h, int x, int dir, int s) {
  if (dir == 0 || dir == 3) {
    x = h + h - 2 - x;
  }
  x = (x + s) % (h + h - 2);
  if (x >= h) {
    if (dir < 2) dir = 0;
    else dir = 3;
    x = h + h - 2 - x;
  } else {
    if (dir < 2) dir = 1;
    else dir = 2;
  }
  return make_pair(x, dir);
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, m;
  cin >> h >> w >> m;
  vector<vector<int>> g(h, vector<int>(w, -1));
  vector<tuple<int, int, int>> ss(m);
  for (int i = 0; i < m; i++) {
    int x, y, s, d, z;
    cin >> x >> y >> s >> d >> z;
    --x; --y; --d;
    g[x][y] = i;
    ss[i] = make_tuple(s, d, z);
  }
  int ans = 0;
  for (int j = 0; j < w; j++) {
    for (int i = 0; i < h; i++) {
      if (g[i][j] >= 0) {
        ans += get<2>(ss[g[i][j]]);
        g[i][j] = -1;
        break;
      }
    }
    vector<vector<int>> new_g(h, vector<int>(w, -1));
    for (int x = 0; x < h; x++) {
      for (int y = 0; y < w; y++) {
        if (g[x][y] == -1) {
          continue;
        }
        auto[s, d, z] = ss[g[x][y]];
        int nx = x;
        int ny = y;
        int nd = d;
        if (d <= 1) {
          tie(nx, nd) = F(h, x, d, s);
        } else {
          tie(ny, nd) = F(w, y, d, s);
        }
        assert(nx >= 0 && ny >= 0 && nx < h && ny < w);
        assert(nd >= 0 && nd < 4);
        ss[g[x][y]] = make_tuple(s, nd, z);
        if (new_g[nx][ny] == -1 || z > get<2>(ss[new_g[nx][ny]])) {
          new_g[nx][ny] = g[x][y];
        }
      }
    }
    swap(g, new_g);
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