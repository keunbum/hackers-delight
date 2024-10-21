#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<string> solution(vector<vector<int>> line) {
  vector<pair<long long, long long>> ps;
  for (int i = 0; i < (int) line.size(); i++) {
    for (int j = i + 1; j < (int) line.size(); j++) {
      long long A = line[i][0];
      long long B = line[i][1];
      long long E = line[i][2];
      long long C = line[j][0];
      long long D = line[j][1];
      long long F = line[j][2];
      if (A * D - B * C == 0) {
        continue;
      }
      long long px = B * F - E * D;
      long long qx = A * D - B * C;
      long long py = E * C - A * F;
      long long qy = A * D - B * C;
      if (px % qx != 0 || py % qy != 0) {
        continue;
      }
      ps.emplace_back(px / qx, py / qy);
    }
  }
  sort(ps.begin(), ps.end());
  ps.resize(unique(ps.begin(), ps.end()) - ps.begin());
  debug(ps);
  auto[min_x, min_y] = ps[0];
  auto[max_x, max_y] = ps[0];
  for (int i = 1; i < (int) ps.size(); i++) {
    min_x = min(min_x, ps[i].first);
    min_y = min(min_y, ps[i].second);
    max_x = max(max_x, ps[i].first);
    max_y = max(max_y, ps[i].second);
  }
  auto axis = make_pair(min_x, max_y);
  long long h = max_y - min_y + 1;
  long long w = max_x - min_x + 1;
  debug(h, w);
  vector<string> ret(h, string(w, '.'));
  for (const auto& p : ps) {
    auto pp = make_pair(axis.second - p.second, p.first - axis.first);
    debug(p, axis, pp);
    assert(0 <= pp.first && pp.first < h && 0 <= pp.second && pp.second < w);
    ret[pp.first][pp.second] = '*';
  }
  debug(ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}});
  solution({{0, 1, -1}, {1, 0, -1}, {1, 0, 1}});
  solution({{1, -1, 0}, {2, -1, 0}});
  solution({{1, -1, 0}, {2, -1, 0}, {4, -1, 0}});
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