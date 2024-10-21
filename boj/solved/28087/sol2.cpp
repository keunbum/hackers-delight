#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, m;
  cin >> N >> m;
  int sum = 0;
  vector<int> v;
  for (int i = 1; i <= m; ++i) {
    int s;
    cin >> s;
    if (N <= s && s <= 2 * N) {
      cout << 1 << '\n' << i << '\n';
      return 0;
    }
    if (s < N) {
      v.push_back(i);
      sum += s;
      if (sum >= N) {
        cout << v.size() << '\n';
        for (int x : v) {
          cout << x << '\n';
        }
        return 0;
      }
    }
  }
  assert(false);
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