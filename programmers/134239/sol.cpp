#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<double> solution(int k, vector<vector<int>> ranges) {
  vector<long long> sum{0};
  while (k != 1) {
    if (k % 2 == 1) {
      sum.push_back(sum.back() + k);
      k = k * 3 + 1;
    }
    while (k % 2 == 0) {
      sum.push_back(sum.back() + k);
      k /= 2;
    }
  }
  sum.push_back(sum.back() + k);
  debug(sum);
  vector<double> ret;
  int n = (int) sum.size() - 1;
  for (auto& range : ranges) {
    int i = range[0];
    int j = n - 1 + range[1];
    if (i > j) {
      ret.push_back(-1);
    } else {
      ret.push_back((sum[j] - sum[i] + sum[j + 1] - sum[i + 1]) * 0.5);
    }
  }
  debug(ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution(5, {{0,0},{0,-1},{2,-3},{3,-3}});
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
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/