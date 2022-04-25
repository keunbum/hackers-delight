#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  constexpr int N = 5;
  array<array<char, N>, N> s;
  vector<tuple<int, int, string>> que;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> s[i][j];
      que.emplace_back(i, j, string(1, s[i][j]));
    }
  }
  for (int iter = 0; iter < 5; iter++) {
    vector<tuple<int, int, string>> new_que;
    for (int b = 0; b < (int) que.size(); b++) {
      auto[mi, mj, str] = que[b];
      for (int dir = 0; dir < 4; dir++) {
        int ni = mi + "2101"[dir] - '1';
        int nj = mj + "1210"[dir] - '1';
        if (ni < 0 || nj < 0 || ni >= N || nj >= N) {
          continue;
        }
        new_que.emplace_back(ni, nj, str + s[ni][nj]);
      }
    }
    debug(new_que.size());
    swap(que, new_que);
  }                                                      
  set<string> ss;
  for (auto& e : que) {
    ss.insert(get<2>(e));
  }
  cout << ss.size() << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
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