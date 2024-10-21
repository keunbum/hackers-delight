#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<string> solution(vector<string> orders, vector<int> course) {
  const int alpha = 26;
  int n = (int) orders.size();
  vector<int> masks(n, 0);
  for (int i = 0; i < n; i++) {
    for (char ch : orders[i]) {
      masks[i] |= (1 << (int) (ch - 'A'));
    }
  }
  array<bool, 11> want{};
  for (int c : course) {
    want[c] = true;
  }
  array<int, 11> max_cnts{};
  array<vector<int>, 11> auxs;
  for (int menus = 0; menus < (1 << alpha); menus++) {
    int menu_cnt = __builtin_popcount(menus);
    if (!want[menu_cnt]) {
      continue;
    }
    int order_cnt = 0;
    for (int mask : masks) {
      order_cnt += (mask & menus) == menus;
    }
    if (order_cnt < 2) {
      continue;
    }
    if (order_cnt > max_cnts[menu_cnt]) {
      max_cnts[menu_cnt] = order_cnt;
      vector<int>().swap(auxs[menu_cnt]);
      auxs[menu_cnt].push_back(menus);
    } else
    if (order_cnt == max_cnts[menu_cnt]) {
      auxs[menu_cnt].push_back(menus);
    }
  }
  vector<string> ret;
  for (int c : course) {
    for (int group : auxs[c]) {
      string s;
      for (int i = 0; i < alpha; i++) {
        if ((group >> i) & 1) {
          s += (char) i + 'A';
        }
      }
      ret.push_back(s);
    }
  }  
  sort(ret.begin(), ret.end());
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2,3,4});
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