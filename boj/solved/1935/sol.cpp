#include <bits/stdc++.h>

using namespace std;

inline void F(double& x, double y, char op) {
  if (op == '+') x += y;
  if (op == '-') x -= y;
  if (op == '*') x *= y;
  if (op == '/') x /= y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string exp;
  cin >> exp;
  vector<int> mp(128, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[(char) (i + 'A')] = x;
  }
  vector<double> stk;
  for (char ch : exp) {
    if (ch >= 'A' && ch <= 'Z') {
      stk.push_back((double) mp[ch]);
    } else {
      double x = stk.back();
      stk.pop_back();
      F(stk.back(), x, ch);
    }
  }
  cout << fixed << setprecision(2) << (stk.back() + 1e-9) << '\n';
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