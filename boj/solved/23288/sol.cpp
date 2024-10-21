#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> score(h * w, 0);
  vector<int> anc(h * w, -1);
  function<void(int, int, int , int)> Dfs = [&](int i, int j, int ai, int aj) {
    score[i * w + j] = 1;
    for (int dir = 0; dir < 4; dir++) {
      int ni = i + dx[dir];
      int nj = j + dy[dir];
      if (min(ni, nj) < 0 || ni >= h || nj >= w || a[i][j] != a[ni][nj] || score[ni * w + nj] != 0) {
        continue;
      }
      anc[ni * w + nj] = ai * w + aj;
      Dfs(ni, nj, ai, aj);
      score[i * w + j] += score[ni * w + nj];
    }
  };
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (score[i * w + j] == 0) {
        anc[i * w + j] = i * w + j;
        Dfs(i, j, i, j);             
      }
    }
  }
  vector<int> dice{1, 2, 3, 4, 5, 6};
  int ret = 0;
  int dir = 1;
  int x = 0;
  int y = 0;
  for (int kk = 0; kk < k; kk++) {
    /*
    cerr << "kk = " << kk << endl;
    cerr << "x, y = " << x << " " << y << endl;
    cerr << "dir = " << dir << endl;
    cerr << "ret = " << ret << endl;
    cerr << "before dice = " << dice[0] << dice[1] << dice[2] << dice[3] << dice[4] << dice[5] << endl;*/
    {
      while (true) {
        assert(dir >= 0 && dir < 4);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
          x = nx;
          y = ny;
          break;
        }
        dir ^= 2;
      }
      assert(x >= 0 && y >= 0 && x < h && y < w);
//      cerr << "nx, ny = " << x << " " << y << endl;
      if (dir == 0) {
        dice = {dice[1], dice[5], dice[2], dice[3], dice[0], dice[4]};
      }
      if (dir == 1) {
        dice = {dice[3], dice[1], dice[0], dice[5], dice[4], dice[2]};
      }
      if (dir == 2) {
        dice = {dice[4], dice[0], dice[2], dice[3], dice[5], dice[1]};
      }
      if (dir == 3) {
        dice = {dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]};
      }
    }
//    cerr << "after dice = " << dice[0] << dice[1] << dice[2] << dice[3] << dice[4] << dice[5] << endl;
    int A = dice[5];
    int B = a[x][y];
    int C = score[anc[x * w + y]];
//    cerr << "A, B, C = " << A << " " << B << " " << C << endl;
    {
      ret += B * C;
    }
    {
      if (A > B) {
        dir = (dir + 3) % 4;
      }
      if (A < B) {
        dir = (dir + 1) % 4;
      }
    }
//    cerr << endl;
  }
  cout << ret << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
*/