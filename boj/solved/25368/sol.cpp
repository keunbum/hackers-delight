#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
vector<vector<int>> dirss;

int aWin, bWin, draw;

int max_diff = 0;
array<array<int, 5>, 5> a;
void DFS(vector<int> xs, vector<int> ys, vector<int> cnt, int apple) {
  debug(xs, ys, cnt);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == xs[0] && j == ys[0]) {
        cerr << 'A';
      } else
      if (i == xs[1] && j == ys[1]) {
        cerr << 'B';
      } else {
        cerr << a[i][j];
      }
      cerr << " \n"[j == 4];
    }
  }
  cerr << '\n';

  bool moved = false;
  for (auto dirs : dirss) {
    vector<int> ncnt(cnt);
    vector<int> nxs(2);
    vector<int> nys(2);
    vector<int> pre_vs(2, -2);
    int flag = 0;
    int napple = apple;
    for (int t = 0; t < 2; t++) {
      nxs[t] = xs[t] + dx[dirs[t]];
      nys[t] = ys[t] + dy[dirs[t]];
      if (min(nxs[t], nys[t]) < 0 || max(nxs[t], nys[t]) >= 5 || a[nxs[t]][nys[t]] == -1) {
        nxs[t] = xs[t];
        nys[t] = ys[t];
        continue;
      }
      pre_vs[t] = a[nxs[t]][nys[t]];
      flag |= (1 << t);
      ncnt[t] += a[nxs[t]][nys[t]] == 1;
      a[nxs[t]][nys[t]] = -1;
      napple -= 1;
    }
    if (flag > 0) {
      DFS(nxs, nys, ncnt, napple);
      moved = true;
    }
    for (int t = 0; t < 2; t++) {
      if (pre_vs[t] != -2) {
        a[nxs[t]][nys[t]] = pre_vs[t];
      }
    }
  }
  if (!moved || apple == 0) {
    int diff = cnt[0] - cnt[1];
    aWin += diff > 0;
    bWin += diff < 0;
    draw += diff == 0;
    debug(max_diff, cnt[0], cnt[1], diff);
    if (abs(diff) > abs(max_diff)) {
      max_diff = diff;
    }
  }   
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      dirss.push_back({i, j});
    }
  }
  int apple = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
      apple += (a[i][j] == 1);
    }
  }
  int xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  a[xa][ya] = a[xb][yb] = -1;
  DFS({xa, xb}, {ya, yb}, {0, 0}, apple);
  debug(max_diff, aWin, bWin, draw);
  cout << (max_diff > 0) << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/