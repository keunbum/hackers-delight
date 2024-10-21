#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<int> row(h, 0);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int t = a[i][j];
      while (t > 0) {
        row[i] += (t % 10 == 9);
        t /= 10;
      }
    }
  }
  vector<int> col(w, 0);
  for (int j = 0; j < w; j++) {
    for (int i = 0; i < h; i++) {
      int t = a[i][j];
      while (t > 0) {
        col[j] += (t % 10 == 9);
        t /= 10;
      }
    }
  }
  int ans = accumulate(row.begin(), row.end(), 0) - max(*max_element(row.begin(), row.end()), *max_element(col.begin(), col.end()));
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