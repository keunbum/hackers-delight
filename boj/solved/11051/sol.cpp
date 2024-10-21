#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int md = (int) 1e4 + 7;
  int n, k;
  cin >> n >> k;
  vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    C[i][0] = C[i][i] = 1;
    C[i][1] = i;
    for (int j = 2; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % md;
    }
  }
  cout << C[n][k] << '\n';
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
*/