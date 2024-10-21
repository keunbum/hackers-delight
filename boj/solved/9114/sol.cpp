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
  while (tt--) {
    const int N = 8;
    array<string, N> s;
    for (int i = 0; i < N; i++) {
      cin >> s[i];
    }
    int sxk, syk, sxp, syp;
    cin >> sxk >> syk >> sxp >> syp;
    bool white_win = true;
    int step
    for (step = 1; step <= N; step++) {
      int xp = sxp;
      int yp = syp;
      auto WhiteMove() {
        for (int dx = -1; dx < 2; dx++) {
          for (int dy = -1; dy < 2; dy++) {
            if (dx == 0 && dy == 0) {
              continue;
            }
      };
      if (!WhiteMove()) {
        white_win = false;
        break;
      }
      if (WhiteCapture()) {
        break;
      }
      if (xp == N - 1) {
        white_win = false;
        break;
      }
      if (!BlackMove()) {
        break;
      }
    }
    assert(step != N + 1);
    cout << white_win ? "White" : "Black" << '\n';
  }
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