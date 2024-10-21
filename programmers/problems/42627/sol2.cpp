#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<vector<int>> jobs) {
  sort(jobs.begin(), jobs.end());
  int n = (int) jobs.size();
  int beg = 0;
  int ret = 0;
  while (beg < n) {
    ret += jobs[beg][1];
    auto Cmp = [&](int i, int j) {
      return jobs[i][1] > jobs[j][1];
    };
    priority_queue<int, vector<int>, decltype(Cmp)> s(Cmp);
    int T = jobs[beg][0] + jobs[beg][1];
    int end = beg + 1;
    while (true) {
      while (end < n && jobs[end][0] < T) {
        s.push(end);
        end += 1;
      }
      if (s.empty()) {
        beg = end;
        break;
      }
      int i = s.top();
      s.pop();
      ret += (T - jobs[i][0]) + jobs[i][1];
      T += jobs[i][1];
    }
  }
  ret /= n;
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