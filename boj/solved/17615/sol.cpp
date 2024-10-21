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
  string s;
  cin >> n >> s;
  vector<int> reds;
  vector<int> blues;
  int beg = 0;
  while (beg < n) {
    int end = beg;
    while (end < n && s[beg] == s[end]) {
      end += 1;
    }
    (s[beg] == 'R' ? reds : blues).push_back(end - beg);
    beg = end;
  }
  int red = accumulate(reds.begin(), reds.end(), 0);
  int blue = accumulate(blues.begin(), blues.end(), 0);
  if (red == 0 || blue == 0) {
    cout << 0 << '\n';
    return 0;
  }
  cout << min(red - max(s[0] == 'R' ? reds[0] : 0, s[n - 1] == 'R' ? reds.back() : 0),
    blue - max(s[0] == 'B' ? blues[0] : 0, s[n - 1] == 'B' ? blues.back() : 0)) << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
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