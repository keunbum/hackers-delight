#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  getline(cin, s);
  int balance = 0;
  string ret;
  string cur;
  for (char ch : s) {
    if (ch == '<') {
      reverse(cur.begin(), cur.end());
      ret += cur;
      cur = "";
      balance += 1;
    }
    if (ch == '>') {
      balance -= 1;
    }
    if (balance > 0) {
      ret += ch;
      continue;
    }
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
      cur += ch;
      continue;
    }
    if (ch == ' ') {
      reverse(cur.begin(), cur.end());
      ret += cur;
      cur = "";
    }     
    ret += ch;
  }
  reverse(cur.begin(), cur.end());
  ret += cur;
  cout << ret << '\n';
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