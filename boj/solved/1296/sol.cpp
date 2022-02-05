#include <bits/stdc++.h>

using namespace std;

const int md = 100;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string name;
  cin >> name;
  auto GetA = [&](const string& s) {
    vector<int> ret(4, 0);
    for (char ch : s) {
      if (ch == 'L') ++ret[0];
      if (ch == 'O') ++ret[1];
      if (ch == 'V') ++ret[2];
      if (ch == 'E') ++ret[3];
    }
    return ret;
  };
  auto a = GetA(name);
  int n;
  cin >> n;
  vector<string> teams(n);
  for (int i = 0; i < n; i++) {
    cin >> teams[i];
  }
  sort(teams.begin(), teams.end());
  auto GetP = [&](const string& s) {
    auto b = GetA(s);
    for (int i = 0; i < 4; i++) {
      b[i] += a[i];
    }
    int ret = 1;
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        ret = (ret * (b[i] + b[j])) % md;
      }
    }
    return ret;
  };
  string ans = *max_element(teams.begin(), teams.end(), [&](const string& si, const string& sj) {
    return GetP(si) < GetP(sj);
  });
  cout << ans << '\n';
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