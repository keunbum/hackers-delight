#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(int h, int w, vector<vector<int>> queries) {
  vector<int> ret;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    iota(a[i].begin(), a[i].end(), i * w + 1);
  }
  debug(a);
  for (vector<int>& q : queries) {
    auto[xa, ya, xb, yb] = make_tuple(q[0], q[1], q[2], q[3]);
    --xa; --ya; --xb; --yb;
    {
      int h = xb - xa + 1;
      int w = yb - ya + 1;
      vector<int> v;
      for (int j = ya; j < yb; j++) v.push_back(a[xa][j]);
      for (int i = xa; i < xb; i++) v.push_back(a[i][yb]);
      for (int j = yb; j > ya; j--) v.push_back(a[xb][j]);
      for (int i = xb; i > xa; i--) v.push_back(a[i][ya]);
      assert((int) v.size() == (h + w) * 2 - 4);
      debug("before", v);
      ret.push_back(*min_element(v.begin(), v.end()));
      rotate(v.rbegin(), v.rbegin() + 1, v.rend());
      debug("after", v);
      int cnt = 0;
      for (int j = ya; j < yb; j++) a[xa][j] = v[cnt++];
      for (int i = xa; i < xb; i++) a[i][yb] = v[cnt++];
      for (int j = yb; j > ya; j--) a[xb][j] = v[cnt++];
      for (int i = xb; i > xa; i--) a[i][ya] = v[cnt++];
      assert(cnt == (int) v.size());
      debug(a);
    }
  }
  assert(ret.size() == queries.size());
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  debug(solution(6,	6,	{{2,2,5,4},{3,3,6,6},{5,1,6,3}}));
  debug(solution(3,	3,	{{1,1,2,2},{1,2,2,3},{2,1,3,2},{2,2,3,3}}	));
//  debug(solution(100,	97,	{{1,1,100,97}}));
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