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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  vector<vector<int>> p(h + 1, vector<int>(w + 1, 0));
  int ans = h * w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + ((s[i][j] == 'W') ^ ((i + j) % 2));
    }
  }
  for (int i = k; i <= h; i++) {
    for (int j = k; j <= w; j++) {
      int cnt = p[i][j] - p[i][j - k] - p[i - k][j] + p[i - k][j - k];
      ans = min({ans, cnt, k * k - cnt});
    }
  }
  cout << ans << '\n';
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