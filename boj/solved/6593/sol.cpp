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
  while (true) {
    int f, h, w;
    cin >> f >> h >> w;
    if (f + h + w == 0) {
      break;
    }
    vector<vector<string>> s(f, vector<string>(h));
    int sk, si, sj, ek, ei, ej;
    for (int k = 0; k < f; k++) {
      for (int i = 0; i < h; i++) {
        cin >> s[k][i];
        for (int j = 0; j < w; j++) {
          if (s[k][i][j] == 'S') {
            sk = k;
            si = i;
            sj = j;
          }
        }
      }
    }
    vector<vector<vector<int>>> dist(f, vector<vector<int>>(h, vector<int>(w, -1)));
    vector<tuple<int, int, int>> que(1, make_tuple(sk, si, sj));
    dist[sk][si][sj] = 0;
    bool ok = false;
    for (int b = 0; b < (int) que.size(); b++) {
      auto[ck, ci, cj] = que[b];
      if (s[ck][ci][cj] == 'E') {
        ek = ck;
        ei = ci;
        ej = cj;
        ok = true;
        break;
      }
      for (int dk = -1; dk <= 1; dk++) {
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            if (dk * dk + di * di + dj * dj != 1) {
              continue;
            }
            int nk = ck + dk;
            int ni = ci + di;
            int nj = cj + dj;
            if (nk >= 0 && ni >= 0 && nj >= 0 && nk < f && ni < h && nj < w && s[nk][ni][nj] != '#' && dist[nk][ni][nj] == -1) {
              dist[nk][ni][nj] = dist[ck][ci][cj] + 1;
              que.emplace_back(nk, ni, nj);
            }
          }
        }
      }
    }
    if (ok) {
      cout << "Escaped in " << dist[ek][ei][ej] << " minute(s)." << '\n';
    } else {
      cout << "Trapped!" << '\n';
    }
  }
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