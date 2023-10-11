#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<int> solution(vector<string> names, vector<int> yearnings, vector<vector<string>> photos) {
  unordered_map<string, int> mp;
  for (int i = 0; i < (int) names.size(); ++i) {
    mp[names[i]] = i;
  }
  vector<int> ret;
  for (auto& p : photos) {
    int sum = 0;
    for (auto& who : p) {
      auto it = mp.find(who);
      if (it != mp.end()) {
        sum += yearnings[it->second];
      }
    }
    ret.push_back(sum);
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