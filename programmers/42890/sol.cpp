#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<vector<string>> relation) {
  int h = (int) relation.size();
  int w = (int) relation[0].size();
  auto IsUnique = [&](int js) {
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if ((js >> j) & 1) {
          s[i] += relation[i][j];
        }
      }
    }
    sort(s.begin(), s.end());
    return adjacent_find(s.begin(), s.end()) == s.end();
  };
  vector<int> ret;
  for (int s = 1; s < (1 << w); s++) {
    if (IsUnique(s) && all_of(ret.begin(), ret.end(), [&](int t) { return (s | t) != s; })) {
      ret.push_back(s);
    }
  }
  return ret.size();
}

int main() {
  cout << solution({{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}}) << endl;
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