#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(vector<string> gems) {
  map<string, int> mp;
  auto Get = [&](string& s) {
    if (mp.find(s) == mp.end()) {
      return mp[s] = (int) mp.size();
    }
    return mp[s];
  };
  int n = (int) gems.size();
  vector<vector<int>> indices(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int id = Get(gems[i]);
    a[i] = id;
    indices[id].push_back(i);
  }
  int uniq = (int) mp.size();
  if (uniq == 1) {
    return {1, 1};
  }
  indices.resize(uniq);
  debug(n, uniq);
  int L = 0;
  int R = -1;
  set<int> s;
  vector<pair<int, int>> res;
  debug(a);
  debug(indices);
  while (L < n) {
    while (L < n - 1 && a[L] == a[L + 1]) {
      L += 1;
    }
    debug(L, a[L]);
    s.insert(a[L]);
    if (R == -1) {
      R = L + 1;
    }
    debug(s);
    while (R < n && (int) s.size() < uniq) {
      s.insert(a[R]);
      R += 1;
    }
    if ((int) s.size() < uniq) {
      break;
    }
    debug(R - 1, a[R - 1]);
    res.emplace_back(L, R - 1);
    int ptr = (int) (upper_bound(indices[a[L]].begin(), indices[a[L]].end(), L + 1) - indices[a[L]].begin());
    debug(L, a[L], ptr);
    if (ptr >= (int) indices[a[L]].size() || indices[a[L]][ptr] >= R) {
      s.erase(a[L]);
    }
    L += 1;
  }
  assert(!res.empty());
  auto[retL, retR] = *min_element(res.begin(), res.end(), [](auto& pi, auto& pj) {
    int iL = pi.second - pi.first;
    int jL = pj.second - pj.first;
    return iL < jL;
  });
  debug(res, retL, retR);
  return {retL + 1, retR + 1};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
//  solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"});
  solution({"XYZ", "XYZ", "XYZ"});
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
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/