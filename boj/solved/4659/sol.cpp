#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    string s;
    cin >> s;
    if (s == "end") {
      break;
    }
    bool ok = false;
    auto IsVowel = [&](char ch) { return strchr("aeiou", ch) != nullptr; };
    for (char ch : s) {
      ok |= IsVowel(ch);
    }
    int n = int(s.size());
    for (int i = 0; i <= n - 3; ++i) {
      ok &= IsVowel(s[i]) != IsVowel(s[i + 1]) || IsVowel(s[i]) !=  IsVowel(s[i + 2]);
    }
    for (int i = 0; i <= n - 2; ++i) {
      ok &= s[i] != s[i + 1] || s[i] == 'e' || s[i] == 'o';
    }
    cout << "<" << s << "> is " << (ok ? "" : "not ") << "acceptable." << '\n';
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * Do I have to solve like this?
  
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