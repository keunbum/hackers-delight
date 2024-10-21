#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> ret;
  while (n--) {
    string s;
    cin >> s;
    int n = int(s.size());
    string cur;
    for (int i = 0; i <= n; ++i) {
      if (i == n || isalpha(s[i])) {
        if (!cur.empty()) {
          ret.push_back(cur);
          cur.clear();
        }
        continue;
      }
      if (cur.size() == 1 && cur[0] == '0') {
        cur.pop_back();
      }
      cur += s[i];
    }
  }
  sort(ret.begin(), ret.end(), [](const string& si, const string& sj) {
    return si.size() < sj.size() || (si.size() == sj.size() && si < sj);
  });
  for (string& x : ret) {
    cout << x << '\n';
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * Do I have to solve like this?
  
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