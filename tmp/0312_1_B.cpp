#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(int n, bool clockwise) {
  vector<vector<int>> a(n, vector<int>(n, 0));
  const int x[4] = {0, 0, n - 1, n - 1};
  const int y[4] = {0, n - 1, n - 1, 0};
  const int dirs[2][4] = {{0, 3, 2, 1}, {1, 0, 3, 2}};
  const int di[4] = {1, 0, -1, 0};
  const int dj[4] = {0, 1, 0, -1};
  int z[4];
  int w[4];
  if (n % 2 == 1) {
    for (int i = 0; i < 4; i++) {
      z[i] = w[i] = n / 2;
    }
  } else {
    int nn = n / 2;
    z[0] = nn; w[0] = nn;
    z[1] = nn; w[1] = nn - 1;
    z[2] = nn - 1; w[2] = nn - 1;
    z[3] = nn - 1; w[3] = nn;
  }
  auto Run = [&](int ci, int cj, int dir, int ei, int ej) {
    int cur = 1;
    for (int space = 1; space <= n / 2; space++) {
      while (true) {
        assert(min(ci, cj) >= 0 && max(ci, cj) < n);
        assert(a[ci][cj] == 0);
        a[ci][cj] = cur++;
        int ni = ci + di[dir];
        int nj = cj + dj[dir];
        if ((dir == 1 && nj > n - 1 - space) || (dir == 3 && nj < space) || (dir == 0 && ni > n - 1 - space) || (dir == 2 && ni < space)) {
          if (clockwise) {
            dir = (dir + 3) % 4;
          } else {
            dir = (dir + 1) % 4;
          }
          ci += di[dir];
          cj += dj[dir];
          break;
        }
        ci = ni;
        cj = nj;
      }
    }
    return cur;
  };                 
  int last;
  for (int i = 0; i < 4; i++) {
    last = Run(x[i], y[i], dirs[clockwise][i], z[i], w[i]);
  }
  if (n % 2 == 1) {
    a[n / 2][n / 2] = last;
  }
  return a;
}

int main() {
  solution(31, true);
  solution(31, false);
  /*solution(999, true);
  solution(999, false);
  solution(1000, true);
  solution(1000, false);*/
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