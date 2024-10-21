#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(vector<int> p, vector<int> s) {
  int n = (int) p.size();
  vector<int> days(n);
  for (int i = 0; i < n; i++) {
    days[i] = (100 - p[i] + s[i] - 1) / s[i];
  }
  vector<int> ret;
  int beg = 0;
  while (beg < n) {
    int end = beg + 1;
    while (end < n && days[beg] >= days[end]) {
      end += 1;
    }
    ret.push_back(end - beg);
    beg = end;
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