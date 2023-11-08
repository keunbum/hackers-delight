#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    string s;
    cin >> s;
    if (s == "CU") cout << "see you"; else
    if (s == ":-)") cout << "I’m happy"; else
    if (s == ":-(") cout << "I’m unhappy"; else
    if (s == ";-)") cout << "wink"; else
    if (s == ":-P") cout << "stick out my tongue"; else
    if (s == "(~.~)") cout << "sleepy"; else
    if (s == "TA") cout << "totally awesome"; else
    if (s == "CCC") cout << "Canadian Computing Competition"; else
    if (s == "CUZ") cout << "because"; else
    if (s == "TY") cout << "thank-you"; else
    if (s == "YW") cout << "you’re welcome"; else
    if (s == "TTYL") cout << "talk to you later";
    else cout << s;
    cout << '\n';    
    if (s == "TTYL") break;
  }
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