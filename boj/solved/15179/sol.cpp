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
  getline(cin, a);
  getline(cin, b);
  while (a.back() == '\n' || a.back() == '\r') a.pop_back();
  while (b.back() == '\n' || b.back() == '\r') b.pop_back();
  int n;
  cin >> n;
  string s;
  cin >> s;
  array<int, 2> score{};
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'S') continue;
    if (s[i] == 'H') score[i % 2] += 1;
    if (s[i] == 'D') score[i % 2] = min(score[i % 2] + 2, 7);
    if (s[i] == 'O') score[(i % 2) ^ 1] += 1;
    if (score[0] == 7 || score[1] == 7) break;
  }
  cout << a << " " << score[0] << " " << b << " " << score[1] << ". ";
  if (score[0] == score[1]) {
    cout << "All square.";
  } else {
    cout << (score[0] > score[1] ? a : b) << " " << (score[0] == 7 || score[1] == 7 ? "has won." : "is winning.");
  }
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