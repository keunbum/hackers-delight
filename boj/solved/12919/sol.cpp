#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  unordered_set<string> ss;
  ss.insert(b);
  vector<string> que(1, b);
  while (!que.empty()) {
    vector<string> nque;
    for (string& t : que) {
      if (t.back() == 'A') {
        string u = t;
        u.pop_back();
        if (u == a) {
          cout << 1 << '\n';
          return 0;
        }
        if (ss.insert(u).second) {
          nque.push_back(u);
        }
      }
      if (t.front() == 'B') {
        string u = t;
        reverse(u.begin(), u.end());
        u.pop_back();
        if (u == a) {
          cout << 1 << '\n';
          return 0;
        }
        if (ss.insert(u).second) {
          nque.push_back(u);
        }
      }
    }
    swap(que, nque);
  }
  cout << 0 << '\n';
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