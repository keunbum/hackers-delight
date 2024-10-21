#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int ALPHA = 26;

int Encode(char ch) {
  if ('0' <= ch && ch <= '9') {
    return (int) (ch - '0');
  }
  return (int) (ch - 'A');
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    string s;
    cin >> s;
    vector<int> cnt(ALPHA, 0);
    for (char ch : s) {
      cnt[Encode(ch)] += 1;
    }
    const int MAX_LEN = 6;
    const vector<string> ss{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    vector<int> tnt(ALPHA, 0);
    function<bool(string)> DFS = [&](string v) {
      if ((int) v.size() > MAX_LEN) {
        return false;
      }
      bool equal = true;
      bool over = false;
      for (int i = Encode('A'); i <= Encode('Z'); i++) {
        equal &= (tnt[i] == cnt[i]);
        over |= (tnt[i] > cnt[i]);
      }
      if (over) {
        return false;
      }
      if (equal) {         
        cout << v << '\n';
        return true;
      }
      for (char digit : string("0123456789")) {
        for (char ch : ss[Encode(digit)]) {
          tnt[Encode(ch)] += 1;
        }
        if (DFS(v + digit)) {
          return true;
        }
        for (char ch : ss[Encode(digit)]) {
          tnt[Encode(ch)] -= 1;
        }
      }
      return false;
    };
    assert(DFS(""));
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/