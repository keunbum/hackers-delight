#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(vector<string> operations) {
  multiset<int> s;
  for (string& str : operations) {
    int v = stoi(str.substr(2));
    if (str[0] == 'I') {
      s.insert(v);
    }
    if (str[0] == 'D') {
      if (!s.empty()) {
        if (v == 1) {
          s.erase(prev(s.end()));
        } else {
          s.erase(s.begin());
        }
      }
    }
  }
  if (s.empty()) {
    return {0, 0};
  }
  return {*prev(s.end()), *s.begin()};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
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