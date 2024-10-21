#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  map<string, int> mp;
  for (string& s : id_list) {
    mp[s] = (int) mp.size();
  }
  int n = (int) mp.size();
  vector<set<int>> ss(n);
  for (const string& in : report) {
    istringstream sin(in);
    string x, y;
    sin >> x >> y;
    ss[mp[y]].insert(mp[x]);
  }
  vector<int> ret(n, 0);
  for (const auto& s : ss) {
    if (s.size() >= k) {
      for (int id : s) {
        ret[id] += 1;
      }
    }
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