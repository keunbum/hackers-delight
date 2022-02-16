#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
  sort(s.begin(), s.end());
  vector<int> a;
  do {
    int x = 0;
    for (char ch : s) {
      x = x * 10 + (int) (ch - '0');
      a.push_back(x);
    }
  } while (next_permutation(s.begin(), s.end()));
  sort(a.begin(), a.end());
  a.resize((int) (unique(a.begin(), a.end()) - a.begin()));
  int ans = 0;
  for (int x : a) {
    bool ok = (x >= 2);
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        ok = false;
        break;
      }
    }
    ans += ok;
  }
  return ans;
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