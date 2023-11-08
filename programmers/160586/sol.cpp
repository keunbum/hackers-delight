#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<int> solution(vector<string> keymap, vector<string> targets) {
  const int inf = (int) 1e8;
  vector<int> cost(128, inf);
  for (auto& s : keymap) {
    for (int i = 0; i < (int) s.size(); ++i) {
      cost[s[i]] = min(cost[s[i]], i + 1);
    }
  }
  vector<int> ret;
  for (auto& t : targets) {
    bool ok = true;
    int sum = 0;
    for (char ch : t) {
      if (cost[ch] == inf) {
        ok = false;
        break;
      }
      sum += cost[ch];
    }
    ret.push_back(ok ? sum : -1);
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