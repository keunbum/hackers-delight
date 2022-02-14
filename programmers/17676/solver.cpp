#include <bits/stdc++.h>

using namespace std;

int Encode(char ch) { return (int) (ch - '0'); }

const int E[4] = {24, 60, 60, 1000};

int solution(vector<string> lines) {
  if (lines.empty()) {
    return 0;
  }
  vector<pair<int, int>> a(lines.size() * 2);
  for (int i = 0; i < (int) lines.size(); i++) {
    istringstream sin(lines[i]);
    string foo, bar, baz;
    sin >> foo >> bar >> baz;
    int v = 0;
    int u = 0;
    int ptr = 0;
    for (char ch : bar) {
      if (ch == ':' || ch == '.') {
        v = v * E[ptr++] + u;
        u = 0;
        continue;
      }
      u = u * 10 + Encode(ch);
    }
    v = v * E[ptr] + u;
    int s = 0;
    for (int j = 0, e = 1000; j < (int) baz.size() - 1; j++) {
      if (baz[j] == '.') continue;
      s += e * Encode(baz[j]);
      e /= 10;
    }
    a[i + i] = {v - s + 1, 1};
    a[i + i + 1] = {v, -1};
  }
  sort(a.begin(), a.end(), [](pair<int, int>& pi, pair<int, int>& pj) {
    return pi.first < pj.first || (pi.first == pj.first && pi.second > pj.second);
  });
  int L = 0;
  int R = 0;
  int ret = 0;
  int cnt = 0;
  while (R < (int) a.size()) {
    cnt += max(a[R].second, 0);
    while (a[L].first <= a[R].first - 1000) {
      cnt += min(a[L].second, 0);
      L += 1;
    }
    ret = max(ret, cnt);
    R += 1;
  }
  return ret;
}
/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to their limitations
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. keep calm
  
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
*/