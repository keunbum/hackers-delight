#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<string> s(m);
  for (int i = 0; i < m; i++) {
    cin >> s[i];
  }
  string ret(n, ' ');
  int err = 0;
  for (int j = 0; j < n; j++) {
    vector<int> cnt(128, 0);
    for (int i = 0; i < m; i++) {
      cnt[s[i][j]] += 1;
    }
    const string S = "ACGT";
    ret[j] = *max_element(S.begin(), S.end(), [&](const char ch, const char dh) { return cnt[ch] < cnt[dh]; });
    for (int k = 0; k < 4; k++) err += cnt[S[k]];
    err -= cnt[ret[j]];
  }
  cout << ret << "\n" << err << '\n';
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