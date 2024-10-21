#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int h, int w, vector<vector<int>> hole) {
  const int inf = h * w + 1;
  vector<vector<bool>> is_hole(h, vector<bool>(w, false));
  for (auto& h : hole) {
    is_hole[h[0] - 1][h[1] - 1] = true;
  }
  auto Encode = [&](int i, int j, int k) {
    return 2 * (i * w + j) + k;
  };
  auto Decode = [&](int I) {
    int i = I / 2 / w;
    int j = I / 2 % w;
    int k = I % 2;
    return make_tuple(i, j, k);
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  vector<int> dist(h * w * 2, inf);
  {
    int I = Encode(0, 0, 1);
    dist[I] = 0;
    s.emplace(dist[I], I);
  }
  while (!s.empty()) {
    auto[expected, I] = s.top();
    s.pop();
    if (expected != dist[I]) {
      continue;
    }
    auto[i, j, k] = Decode(I);
    if (i == h - 1 && j == w - 1) {
      return dist[I];
    }
    for (int nk = 0; nk <= k; nk++) {
      int L = (k == 1 && nk == 0) + 1;
      for (int di = -L; di <= L; di++) {
        for (int dj = -L; dj <= L; dj++) {
          if (di * di + dj * dj == L) {
            int ni = i + di;
            int nj = j + dj;
            int NI = Encode(ni, nj, nk);
            if (0 <= ni && ni < h && 0 <= nj && nj < w && !is_hole[ni][nj] && dist[I] + 1 < dist[NI]) {
              dist[NI] = dist[I] + 1;
              s.emplace(dist[NI], NI);
            }
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
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