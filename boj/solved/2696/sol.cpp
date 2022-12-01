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
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    int m;
    cin >> m;
    priority_queue<int> A, B;
    vector<int> res;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      debug(i, x);
      if (i % 2 == 0) {
        A.push(x);
      } else {
        B.push(~x);
      }
      if (!B.empty() && A.top() > ~B.top()) {
        int a = A.top();
        A.pop();
        int b = ~B.top();
        debug(a, b);
        B.pop();
        A.push(b);
        B.push(~a);
      }
      if (i % 2 == 0) {
        res.push_back(A.top());
        debug(res);
      }
    }
    assert((int) res.size() == ((m + 1) / 2));
    cout << (qq == 1 ? "" : "\n") << res.size();
    for (int i = 0; i < (int) res.size(); i++) {
      cout << " \n"[i % 10 == 0] << res[i];
    }
  }
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