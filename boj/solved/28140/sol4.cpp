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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> lpos;
  vector<int> rpos;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      lpos.push_back(i);
    }
    if (s[n - 1 - i] == 'B') {
      rpos.push_back(n - 1 - i);
    }
  }
  vector<int> ls(q);
  vector<int> rs(q);
  for (int i = 0; i < q; ++i) {
    cin >> ls[i] >> rs[i];
  }
  vector<int> perm(q);
  iota(perm.begin(), perm.end(), 0);
  vector<array<int, 2>> res(q);
  {
    sort(perm.begin(), perm.end(), [&](int i, int j) {
      return ls[i] < ls[j];
    });
    int ptr = 0;
    for (int i : perm) {
      while (ptr < (int) lpos.size() - 1 && lpos[ptr] < ls[i]) {
        ptr += 1;
      }
      res[i][0] = ptr;
    }
  }
  {
    sort(perm.begin(), perm.end(), [&](int i, int j) {
      return rs[i] > rs[j];
    });
    int ptr = 0;
    for (int i : perm) {
      while (ptr < (int) rpos.size() - 1 && rpos[ptr] > rs[i]) {
        ptr += 1;
      }
      res[i][1] = ptr;
    }
  }
  for (auto[i, j] : res) {
    if (i < (int) lpos.size() - 1 && j < (int) rpos.size() - 1 && lpos[i + 1] < rpos[j + 1]) {
      cout << lpos[i] << ' ' << lpos[i + 1] << ' ' << rpos[j + 1] << ' ' << rpos[j] << '\n';
    } else {
      cout << -1 << '\n';
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
  * think rationally. keep calm
  
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