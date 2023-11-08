#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  auto Encode = [&](int i, int j) {
    return w * i + j;
  };
  vector<string> g(h);
  for (int i = 0; i < h; ++i) {
    cin >> g[i];
  }
  vector<int> cnt(h * w);
  vector<int> p(h * w, -1);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int s = Encode(i, j);
      if (g[i][j] == '0' && p[s] == -1) {
        p[s] = s;
        vector<int> que(1, s);
        for (int b = 0; b < (int) que.size(); ++b) {
          int mi = que[b] / w;
          int mj = que[b] % w;
          for (int dir = 0; dir < 4; ++dir) {
            int ni = mi + "2101"[dir] - '1';
            int nj = mj + "1210"[dir] - '1';
            int ns = Encode(ni, nj);
            if (ni >= 0 && nj >= 0 && ni < h && nj < w && g[ni][nj] == '0' && p[ns] == -1) {
              p[ns] = s;
              que.push_back(ns);
            }
          }
        }
        cnt[s] = que.size();
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (g[i][j] == '1') {
        set<int> ss;
        for (int dir = 0; dir < 4; ++dir) {
          int ni = i + "2101"[dir] - '1';
          int nj = j + "1210"[dir] - '1';
          if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
            ss.insert(p[Encode(ni, nj)]);
          } 
        }
        int sum = 0;
        for (int s : ss) {
          sum += cnt[s];
        }
        g[i][j] = (char) ((sum + 1) % 10 + '0');
      }
    }
    cout << g[i] << '\n';
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  
 * stuff you should look for
  * 0-based or 1-based?
  * off-by-one error
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/