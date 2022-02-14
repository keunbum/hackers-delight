#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string L;
    cin >> L;
    list<char> a;
    list<char>::iterator it = a.begin();
    for (const char ch : L) {
      if (ch == '-') {
        if (!a.empty() && it != prev(a.begin())) {
          it = a.erase(it);
          it = prev(it);
        }
      }
      if (ch == '<') {
        if (it != prev(a.begin())) {
          it = prev(it);
        }
      }
      if (ch == '>') {
        if (it != prev(a.end())) {
          it = next(it);
        }
      }
      if (isalnum(ch)) {
        it = next(it);
        it = a.insert(it, ch);
      }
    }
    cout << string(a.begin(), a.end()) << '\n';
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