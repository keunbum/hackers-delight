#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<string> solution(vector<vector<int>> queries) {
  const vector<array<int, 4>> nx = {
    {0, 0, 0, 0},
    {2, 1, 1, 0},
    {2, 2, 2, 2}
  };
  const array<string, 3> x2s = {"rr", "Rr", "RR"};
  array<int, 16> p4;
  p4[0] = 1;
  for (int i = 1; i < 16; i++) {
    p4[i] = 4 * p4[i - 1];
  }
  vector<string> ret;
  for (auto& query : queries) {
    int n = query[0] - 1;
    int p = query[1] - 1;
    int x = 1;
    while (n--) {
      x = nx[x][p / p4[n] % 4];
    }
    ret.push_back(x2s[x]);
  }
  return ret;
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
  * keep calm
  
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