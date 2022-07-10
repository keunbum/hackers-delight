#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int h, int w, vector<string> board) {
  vector<string> a(w);
  for (int i = 0; i < w; i++) {
    for (int j = h - 1; j >= 0; j--) {
      a[i] += board[j][i];
    }
  }
  debug(board);
  debug(a);
  swap(h, w);
  while (true) {
    debug(a);
    bool changed = false;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    for (int i = 0; i < h - 1; i++) {
      for (int j = 0; j < (int) a[i].size() - 1; j++) {
        if (a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j] && a[i][j] == a[i + 1][j + 1]) {
          changed = true;
          used[i][j] = used[i][j + 1] = used[i + 1][j] = used[i + 1][j + 1] = true;
        }
      }
    }
    if (!changed) {
      break;
    }
    for (int i = 0; i < h; i++) {
      string new_row;
      for (int j = 0; j < (int) a[i].size(); j++) {
        if (!used[i][j]) {
          new_row += a[i][j];
        }
      }
      swap(a[i], new_row);
    }
  }
  int ret = h * w;
  for (const string& s : a) {
    ret -= (int) s.size();
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  debug(solution(4,	5,	{"CCBDE", "AAADE", "AAABF", "CCBBF"}));
  debug(solution(6,	6,	{"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"}	));
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * keep calm
  
 * stuff you should look for
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