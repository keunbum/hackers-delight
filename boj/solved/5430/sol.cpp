﻿#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, l;
    string p, s;
    deque<int> a;
    cin >> p >> n >> s;
    l = s.length();
    for (int i = 1; i < l && s[i] != ']'; ) {
      int v = 0, b, e = 1;
      for (b = i + 1; s[b] != ',' && s[b] != ']'; b++) ;
      for (int j = b - 1; j >= i; j--, e *= 10) {
        v += (s[j] - '0') * e;
      }
      if (v) a.push_back(v);
      i = b + 1;
    }
    l = p.length();
    bool ok = true, tog = false;
    for (int i = 0; i < l; i++) {
      if (p[i] == 'R') { tog ^= true; }
      else if (!a.empty()) {
        if (tog) a.pop_back();
        else a.pop_front();
      }
      else {
        ok = false;
        break; 
      }
    }
    if (!ok) cout << "error" << '\n';
    else {
      n = a.size();
      cout << '[';
      if (!tog) {
        for (int i = 0; i < n; i++) {
          cout << a[i];
          if (i < n - 1) cout << ',';
        }
      } else {
        for (int i = n - 1; i >= 0; i--) {
          cout << a[i];
          if (i > 0) cout << ',';
        }
      }
      cout << ']' << '\n';
    }
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}
