#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

int solution(vector<vector<int>> a) {
  int n = (int) a.size();
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
  const int inf = (int) 1e8;
  vector<int> dist(n * n * 4, inf);
  auto Encode = [&](int i, int j, int dir) {
    return (i * n + j) * 4 + dir;
  };
  auto Decode = [&](int v) {
    int i = v / 4 / n;
    int j = v / 4 % n;
    int d = v % 4;
    return make_tuple(i, j, d);
  };
  s.emplace(0, Encode(0, 0, 0));
  dist[Encode(0, 0, 0)] = 0;
  s.emplace(0, Encode(0, 0, 1));
  dist[Encode(0, 0, 1)] = 0;
  while (!s.empty()) {
    auto[expected, v] = s.top();
    s.pop();
    if (expected != dist[v]) {
      continue;
    }         
    auto[i, j, mdir] = Decode(v);
    debug(i, j, mdir, dist[v]);
    for (int ndir = 0; ndir < 4; ndir++) {
      if (abs(ndir - mdir) == 2) {
        continue;
      }
      int ni = i + di[ndir];
      int nj = j + dj[ndir];
      int u = Encode(ni, nj, ndir);
      int cost = (ndir == mdir ? 100 : 600);
      if (0 <= min(ni, nj) && max(ni, nj) < n && a[ni][nj] == 0 && dist[u] > dist[v] + cost) {
        dist[u] = dist[v] + cost;
        s.emplace(dist[u], u);
      }
    }
  }
  int ret = inf;
  for (int i = 0; i < 4; i++) {
    ret = min(ret, dist[Encode(n - 1, n - 1, i)]);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}});
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
  * int overflow, array bounds (habituation of assert)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/