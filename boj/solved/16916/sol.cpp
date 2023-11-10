#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<int> kmp_table(const string &s) {
  int n = (int) s.size();
  vector<int> p(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && s[i] != s[k]) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    p[i] = k;
  }
  return p;
}

vector<int> kmp_search(const string &s, const string &w, const vector<int> &p) {
  int n = (int) s.size();
  int m = (int) w.size();
  assert(n >= 1 && (int) p.size() == n);
  vector<int> res;
  int k = 0;
  for (int i = 0; i < m; i++) {
    while (k > 0 && (k == n || w[i] != s[k])) {
      k = p[k - 1];
    }
    if (w[i] == s[k]) {
      k++;
    }
    if (k == n) {
      res.push_back(i - n + 1);
    }
  }
  return res;
  // returns 0-indexed positions of occurrences of s in w
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, p;
  cin >> s >> p;
  auto res = kmp_search(p, s, kmp_table(p));
  cout << (!res.empty()) << '\n';
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