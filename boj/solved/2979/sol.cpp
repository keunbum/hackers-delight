#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A, B, C;
  cin >> A >> B >> C;
  vector<int> cnt(101, 0);
  for (int i = 0; i < 3; i++) {
    int st, en;
    cin >> st >> en;
    while (st < en) {
      cnt[st++] += 1;
    }
  }
  const int T[4] = {0, A, B, C};
  int ans = 0;
  for (int i = 1; i <= 100; i++) {
    ans += T[cnt[i]] * cnt[i];
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