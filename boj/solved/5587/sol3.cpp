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
  int n;
  cin >> n;
  string s(n + n, (char) 1);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    --t;
    s[t] = (char) 0;
  }
  int who = 0;
  int top = -1;
  vector<int> cnt(2, n);
  while (cnt[0] > 0 && cnt[1] > 0) {
    int i = s.find((char) who, top + 1);
    if (i == (int) string::npos) {
      top = -1;
    } else {
      top = i;
      s[i] = (char) -1;
      cnt[who] -= 1;
    }
    who ^= 1;
  }
  cout << cnt[1] << '\n' << cnt[0] << '\n';
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
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/