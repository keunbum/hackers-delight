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
  /*char ch;
  string s;
  while (cin >> ch >> s) {
    cout << "mp[\"" << s << "\"] = " << "\'" << ch << "\';" << '\n';
  }*/
  map<string, char> mp;
  mp[".-"] = 'A';
  mp["-..."] = 'B';
  mp["-.-."] = 'C';
  mp["-.."] = 'D';
  mp["."] = 'E';
  mp["..-."] = 'F';
  mp["--."] = 'G';
  mp["...."] = 'H';
  mp[".."] = 'I';
  mp[".---"] = 'J';
  mp["-.-"] = 'K';
  mp[".-.."] = 'L';
  mp["--"] = 'M';
  mp["-."] = 'N';
  mp["---"] = 'O';
  mp[".--."] = 'P';
  mp["--.-"] = 'Q';
  mp[".-."] = 'R';
  mp["..."] = 'S';
  mp["-"] = 'T';
  mp["..-"] = 'U';
  mp["...-"] = 'V';
  mp[".--"] = 'W';
  mp["-..-"] = 'X';
  mp["-.--"] = 'Y';
  mp["--.."] = 'Z';
  mp[".----"] = '1';
  mp["..---"] = '2';
  mp["...--"] = '3';
  mp["....-"] = '4';
  mp["....."] = '5';
  mp["-...."] = '6';
  mp["--..."] = '7';
  mp["---.."] = '8';
  mp["----."] = '9';
  mp["-----"] = '0';
  mp["--..--"] = ',';
  mp[".-.-.-"] = '.';
  mp["..--.."] = '?';
  mp["---..."] = ':';
  mp["-....-"] = '-';
  mp[".--.-."] = '@';
  int n;
  cin >> n;
  string ans;
  while (n--) {
    string s;
    cin >> s;
    ans += mp[s];
  }
  cout << ans << '\n';
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