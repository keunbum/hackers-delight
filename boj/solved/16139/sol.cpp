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
  const int alpha = 26;
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<array<int, alpha>> p(n + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < alpha; j++) {
      p[i + 1][j] = p[i][j];
    }
    p[i + 1][(int) (s[i] - 'a')] += 1;
  } 
  int tt;
  cin >> tt;
  while (tt--) {
    char ch;
    int l, r;
    cin >> ch >> l >> r;
    int j = (int) (ch - 'a');
    cout << (p[r + 1][j] - p[l][j]) << '\n';
  }
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
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/