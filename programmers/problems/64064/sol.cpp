#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

bool Matched(const string& a, const string& b) {
  if (a.size() != b.size()) {
    return false;
  }
  bool ok = true;
  for (int i = 0; i < (int) a.size(); i++) {
    ok &= (a[i] == b[i] || b[i] == '*');
  }
  return ok;
}

int solution(vector<string> user_id, vector<string> banned_id) {
  int ret = 0;
  int n = (int) user_id.size();
  int m = (int) banned_id.size();
  vector<bool> was(1 << n, false);
  vector<bool> used(n, false);
  function<void(int, int)> DFS = [&](int v, int mask) {
    if (v == m) {
      if (!was[mask]) {
        was[mask] = true;
        ret += 1;
      }
      return;
    }
    for (int i = 0; i < n; i++) {
      if (!used[i] && Matched(user_id[i], banned_id[v])) {
        used[i] = true;
        DFS(v + 1, mask | (1 << i));
        used[i] = false;
      }
    }
  };
  DFS(0, 0);
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