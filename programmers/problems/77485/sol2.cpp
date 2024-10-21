#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(int h, int w, vector<vector<int>> queries) {
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    iota(a[i].begin(), a[i].end(), i * w + 1);
  }
  vector<int> ret;
  for (vector<int>& q : queries) {
    auto[xa, ya, xb, yb] = make_tuple(q[0] - 1, q[1] - 1, q[2] - 1, q[3] - 1);
    vector<int> stk(1, a[xa + 1][ya]);
    for (int j = ya; j < yb; j++) {
      stk.push_back(a[xa][j]);
      a[xa][j] = stk[stk.size() - 2];
    }
    for (int i = xa; i < xb; i++) {
      stk.push_back(a[i][yb]);
      a[i][yb] = stk[stk.size() - 2];
    }
    for (int j = yb; j > ya; j--) {
      stk.push_back(a[xb][j]);
      a[xb][j] = stk[stk.size() - 2];
    }
    for (int i = xb; i > xa; i--) {
      stk.push_back(a[i][ya]);
      a[i][ya] = stk[stk.size() - 2];
    }
    stk.pop_back();
    debug(stk);
    assert((int) stk.size() == (xb - xa + yb - ya) * 2);
    ret.push_back(*min_element(stk.begin(), stk.end()));
  }
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