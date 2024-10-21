#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 80;
  vector<string> ret(N + 1);
  ret[1] = "1";
  ret[2] = "12";
  ret[3] = "121";
  ret[4] = "1213";
  ret[5] = "12131";
  ret[6] = "121312";
  ret[7] = "1213121";
  ret[8] = "12131231";
  for (int i = 9; i <= N; i++) {
    for (char ch = '1'; ch <= '3'; ch++) {
      const string& s = ret[i - 1];
      if (s[i - 2] == ch || (s[i - 4] == s[i - 2] && s[i - 3] == ch)) {
        continue;
      }
      ret[i] = s + ch;
      break;
    }
  }
  int n;
  cin >> n;
  cout << ret[n] << '\n';
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
  * performance or safety?
  * local or global?
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