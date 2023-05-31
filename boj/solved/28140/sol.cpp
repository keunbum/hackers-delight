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
  vector<int> ls(q);
  vector<int> rs(q);
  for (int i = 0; i < q; ++i) {
    cin >> ls[i] >> rs[i];
  }
  vector<int> perm(q);
  iota(perm.begin(), perm.end(), 0);
  vector<array<int, 4>> res(q);
  {
    sort(perm.begin(), perm.end(), [&](int i, int j) {
      return ls[i] < ls[j];
    });
    int L = 0;
    int R = 0;
    for (int i : perm) {
      L = max(L, ls[i]);
      while (L < n && s[L] != 'R') {
        L += 1;
      }
      R = max(R, L + 1);
      while (R < n && s[R] != 'R') {
        R += 1;
      }
      res[i][0] = L;
      res[i][1] = R;
    }
  }
  {
    sort(perm.begin(), perm.end(), [&](int i, int j) {
      return rs[i] > rs[j];
    });
    int R = n - 1;
    int L = n - 1;
    for (int i : perm) {
      R = min(R, rs[i]);
      while (R >= 0 && s[R] != 'B') {
        R -= 1;
      }
      L = min(L, R - 1);
      while (L >= 0 && s[L] != 'B') {
        L -= 1;
      }
      res[i][2] = L;
      res[i][3] = R;
    }
  }
  for (auto& v : res) {
    if (v[1] < v[2]) {
      cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << '\n';
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