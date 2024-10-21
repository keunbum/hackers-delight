#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<string> ss) {
  int ret = 0;
  for (string& s : ss) {
    int i = 0;
    bool ok = true;
    string pre = "";
    while (i < (int) s.size()) {
      bool found = false;
      for (string t : {"aya", "ye", "woo", "ma"}) {
        if (s.find(t, i) == i && pre != t) {
          i += t.size();
          pre = t;
          found = true;
        }
      }
      if (!found) {
        ok = false;
        break;
      }
    }
    ret += ok;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({"ayamaayawooye", "ma"});
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
  * int overflow, array bounds (habituation of assert)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/