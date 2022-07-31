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
  int h, w, k;
  cin >> h >> w >> k;
  debug(h, w, k);
  vector<tuple<int, int, int>> fans;
  vector<pair<int, int>> look_for;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int t;
      cin >> t;
      if (t == 0) {
        continue;
      }
      if (t == 5) {
        look_for.emplace_back(i, j);
        continue;
      }
      const array<int, 4> to_my_dir{2, 6, 4, 0};
      fans.emplace_back(i, j, to_my_dir[t - 1]);
    }
  }
  debug(fans);
  debug(look_for);
  int W;
  cin >> W;
  vector<vector<bool>> hor_wall(w, vector<bool>(h - 1, false));
  vector<vector<bool>> ver_wall(h, vector<bool>(w - 1, false));
  while (W--) {
    int x, y, t;
    cin >> x >> y >> t;
    --x; --y;
    if (t == 0) {
      hor_wall[y][x - 1] = true;
    } else {
      ver_wall[x][y] = true;
    }
  }
  for (auto& col : hor_wall) {
    debug(col);
  }
  for (auto& row : ver_wall) {
    debug(row);
  }
  int rnd = 0;
  vector<vector<int>> a(h, vector<int>(w, 0));
  do {
    debug(rnd);
    const array<int, 8> di{1, 1, 0, -1, -1, -1, 0, 1};
    const array<int, 8> dj{0, 1, 1, 1, 0, -1, -1, -1};
    vector<vector<int>> inc(h, vector<int>(w, 0));
    auto IsOpen = [&](int i, int j, int dir) {
      int vj = j - (dir == 6);
      int hi = i - (dir == 4);
      assert(i >= 0 && i < h && vj >= 0 && vj < w);
      assert(hi >= 0 && hi < h && j >= 0 && j < w);
      return (di[dir] == 0 && !ver_wall[i][vj]) || (di[dir] != 0 && !hor_wall[j][hi]);
    };
    {
      debug("STEP1");
      for (auto&[fi, fj, fd] : fans) {
        int si = fi + di[fd];
        int sj = fj + dj[fd];
        //debug(fi, fj, si, sj, fd);
        assert(si >= 0 && sj >= 0 && si < h && sj < w);
        vector<pair<int, int>> que(1, {si, sj});
        vector<vector<bool>> used(h, vector<bool>(w, false));
        used[si][sj] = true;
        inc[si][sj] += 5;
        for (int val = 4; val > 0; val--) {
          vector<pair<int, int>> new_que;
          auto Mod = [&](int dir) {
            return (dir + 8) % 8;
          };
          const array<int, 3> dirs{Mod(fd - 1), fd, Mod(fd + 1)};
          for (auto&[mi, mj] : que) {
            //debug(mi, mj);
            for (int dir : dirs) {
              int ni = mi + di[dir];
              int nj = mj + dj[dir];
              if (ni >= 0 && nj >= 0 && ni < h && nj < w && !used[ni][nj]) {
                if (dir == fd) {
                  if (!IsOpen(mi, mj, dir)) {
                    continue;
                  }
                } else {
                  int dir1 = Mod(dir - 1);
                  int dir2 = Mod(dir + 1);
                  if (dir == Mod(fd + 1)) {
                    swap(dir1, dir2);
                  }
                  if (!IsOpen(mi, mj, dir1) || !IsOpen(mi + di[dir1], mj + dj[dir1], dir2)) {
                    continue;
                  }
                }
                //debug(ni, nj);
                used[ni][nj] = true;
                inc[ni][nj] += val;
                new_que.emplace_back(ni, nj);
              }
            }
          }
          swap(que, new_que);
        }
      }  
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          a[i][j] += inc[i][j];
        }
      }
      for (auto& row : a) {
        debug(row);
      }
    }
    vector<vector<int>> new_a(a);
    {
      debug("STEP2");
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          for (int dir : {0, 2, 4, 6}) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if (ni >= 0 && nj >= 0 && ni < h && nj < w && a[i][j] > a[ni][nj] && IsOpen(i, j, dir)) {
              int ax = (a[i][j] - a[ni][nj]) / 4;
              new_a[i][j] -= ax;
              new_a[ni][nj] += ax;
            }
          }
        }        
      }
      swap(a, new_a); 
      for (auto& row : a) {
        debug(row);
      }
    }
    {
      debug("STEP3");
      for (int i = 0; i < h - 1; i++) {
        a[i][0] = max(0, a[i][0] - 1);
      }
      for (int j = 0; j < w - 1; j++) {
        a[h - 1][j] = max(0, a[h - 1][j] - 1);
      }
      for (int i = h - 1; i > 0; i--) {
        a[i][w - 1] = max(0, a[i][w - 1] - 1);
      }
      for (int j = w - 1; j > 0; j--) {
        a[0][j] = max(0, a[0][j] - 1);
      }
      for (auto& row : a) {
        debug(row);
      }
    }
    rnd += 1;
  } while (rnd <= 100 && !all_of(look_for.begin(), look_for.end(), [&](auto& p) { return a[p.first][p.second] >= k;} ));
  cout << rnd << '\n';
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