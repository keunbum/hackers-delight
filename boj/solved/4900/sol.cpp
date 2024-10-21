#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

map<string, int> mp = {
  {"063", 0},
  {"010", 1},
  {"093", 2},
  {"079", 3},
  {"106", 4},
  {"103", 5},
  {"119", 6},
  {"011", 7},
  {"127", 8},
  {"107", 9},
};

int Decode(const string& s) {
  int ret = 0;
  for (int i = 0; i < int(s.size()); i += 3) {
    ret = 10 * ret + mp[s.substr(i, 3)];
  }
  return ret;
}

string Encode(int x) {
  vector<int> a;
  while (x > 0) {
    a.push_back(x % 10);
    x /= 10;
  }
  reverse(a.begin(), a.end());
  string ret;
  for (int x : a) {
    for (auto&[k, v] : mp) {
      if (v == x) {
        ret += k;
      }
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    string s;
    cin >> s;
    if (s == "BYE") {
      break;
    }
    int i = s.find('+');
    string a = s.substr(0, i);
    string b = s.substr(i + 1, int(s.size()) - i - 2);
    cout << s << Encode(Decode(a) + Decode(b)) << '\n';
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