#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<vector<int>> jobs) {
  int n = (int) jobs.size();
  sort(jobs.begin(), jobs.end());
  int L = 0;
  int ret = 0;
  while (L < (int) jobs.size()) {
    debug(L, jobs[L]);
    ret += jobs[L][1];
    int T = jobs[L][0] + jobs[L][1];
    while (true) {
      int R = L + 1;
      int min_p = 1001;
      int pos = -1;
      debug(T);
      while (R < (int) jobs.size() && jobs[R][0] < T) {
        debug(R, jobs[R]);
        if (jobs[R][1] < min_p) {
          min_p = jobs[R][1];
          pos = R;
        }
        R += 1;
      }
      debug(pos);
      if (pos == -1) {
        L = R;
        break;
      }
      ret += (T - jobs[pos][0]) + jobs[pos][1];
      T += jobs[pos][1];
      jobs.erase(jobs.begin() + pos);
    }        
  }
  ret /= n;
  debug(ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({{0, 3}, {1, 9}, {2, 6}, {3, 3}, {4, 9}, {5, 6}});
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