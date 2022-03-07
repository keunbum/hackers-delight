#include <bits/stdc++.h>

using namespace std;

bool Fine(const string& s) {
  for (int sz = 1; sz <= (int) s.size() / 2; sz++) {
    int p = (int) s.size() - 2 * sz;
    bool same = true;
    for (int i = 0; i < sz; i++) {
      if (s[p + i] != s[p + sz + i]) {
        same = false;
        break;
      }
    }
    if (same) {
      return false;
    }
  }
  return true;
}

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
//  ret[8] = "12131231";
  int n;
  cin >> n;
  for (int i = 8; i <= n; i++) {
    string& s = ret[i - 1];
    s.pop_back();
    s.pop_back();
    for (char ch = '1'; ch <= '3'; ch++, s.pop_back()) {
      s += ch;
      if (!Fine(s)) {
        continue;
      }
      for (char dh = '1'; dh <= '3'; dh++, s.pop_back()) {
        s += dh;
        if (!Fine(s)) {
          continue;
        }
        for (char eh = '1'; eh <= '3'; eh++, s.pop_back()) {
          s += eh;
          if (!Fine(s)) {
            continue;
          }
          ret[i] = s;
          break;
        }
        if (!ret[i].empty()) {
          break;
        }
      }
      if (!ret[i].empty()) {
        break;
      }
    }
    assert(!ret[i].empty());
//    cout << "ret[" << i << "] = \"" << ret[i] << "\";" << endl;
//    cerr << "ret[" << i << "] = \"" << ret[i] << "\";" << endl;
//    cout << (double) clock() / CLOCKS_PER_SEC << "s" << endl;
  }
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