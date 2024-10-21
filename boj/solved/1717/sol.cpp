#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  ++n;
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  auto Get = [&](int x) {
    int r = x;
    while (p[r] != r) {
      r = p[r];
    }
    while (p[x] != r) {
      int y = p[x];
      p[x] = r;
      x = y;
    }
    return r;
  };
  while (m--) {
    int cmd, x, y;
    cin >> cmd >> x >> y;
    if (cmd == 0) {
      p[Get(x)] = Get(y);
    } else {
      cout << (Get(x) == Get(y) ? "yes" : "no") << '\n';
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
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
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