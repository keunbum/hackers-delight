#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int formingMagicSquare(vector<vector<int>> s) {
  vector<int> perm(9);
  iota(perm.begin(), perm.end(), 1);
  int ret = (int) 2e9;
  do {
    vector<int> sums;
    for (int i = 0; i < 3; ++i) {
      int sum = 0;
      for (int j = 0; j < 3; ++j) {
        sum += perm[i * 3 + j];
      }
      sums.push_back(sum);
    }
    for (int j = 0; j < 3; ++j) {
      int sum = 0;
      for (int i = 0; i < 3; ++i) {
        sum += perm[i * 3 + j];
      }
      sums.push_back(sum);
    }
    for (array<int, 3> a : vector<array<int, 3>>{{0, 4, 8}, {2, 4, 6}, {1, 4, 7}, {3, 4, 5}}) {
      sums.push_back(perm[a[0]] + perm[a[1]] + perm[a[2]]);
    }
    if (count(sums.begin(), sums.end(), sums[0]) == (int) sums.size()) {
      int cost = 0;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          cost += abs(perm[i * 3 + j] - s[i][j]);
        }
      }
      ret = min(ret, cost);
    }
  } while (next_permutation(perm.begin(), perm.end()));
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto res = formingMagicSquare({
    {4, 9, 2},
    {3, 5, 7},
    {8, 1, 5}
  });
  debug(res);
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