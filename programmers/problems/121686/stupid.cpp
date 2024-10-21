#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<long long> solution(vector<vector<int>> ps) {
  vector<long long> ret(11, 0);
  sort(ps.begin(), ps.end(), [](auto& pi, auto& pj) {
    return pi[1] < pj[1] || (pi[1] == pj[1] && pi[0] < pj[0]);
  });
//  debug(ps);
  int n = (int) ps.size();
  ret[0] = ps[0][1] + ps[0][2];
  vector<bool> used(n, false);
  used[0] = true;
//  debug(0, ret);
  for (int rot = 1; rot < n; rot++) {
    int j = -1;
    int mn0 = 11;
    int mn1 = (int) 1e8;
//    debug(ret);
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        if (ps[i][1] < ret[0] && (ps[i][0] < mn0 || (ps[i][0] == mn0 && ps[i][1] < mn1))) {
          mn0 = ps[i][0];
          mn1 = ps[i][1];
          j = i;
        }
      }
    }
    if (j != -1) {
//      debug(j, ret);
      used[j] = true;
      ret[ps[j][0]] += ret[0] - ps[j][1];
      ret[0] += ps[j][2];
    } else {
      for (int i = 0; i < n; i++) {
        if (!used[i]) {
          j = i;
          break;
        }
      }
//      debug(j, ret);
      assert(j != -1);
      used[j] = true;
      ret[0] = ps[j][1] + ps[j][2];
    }
  }
//  debug(ret);
  return ret;
}

int main() {                
  ios::sync_with_stdio(false);
  cin.tie(0);
//  solution({{2, 0, 10}, {1, 5, 5}, {3, 5, 3}, {3, 12, 2}});
//  solution({{3, 6, 4}, {4, 2, 5}, {1, 0, 5}, {5, 0, 5}});
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  auto res = solution(a);
  for (int i = 0; i < 11; i++) {
    cout << res[i] << " \n"[i == 10];
  }
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