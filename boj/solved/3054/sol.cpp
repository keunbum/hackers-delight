#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 5;
  const int D = 4;
  const int dx[8] = {0, 1, 1, 2, 2, 3, 3, 4};
  const int dy[8] = {0, -1, 1, -2, 2, -1, 1, 0};
  string s;
  cin >> s;
  vector<string> res(N, string(N + D * (s.size() - 1), '.'));
  for (int i = 0; i < (int) s.size(); i++) {
    char deco = ((i + 1) % 3 == 0 ? '*' : '#');
    int x = 0;
    int y = (N - 3) + D * i;
    for (int dir = 0; dir < 8; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      res[nx][ny] = (res[nx][ny] == '*' ? '*' : deco);
    }
    res[x + 2][y] = s[i];
  }
  for (int i = 0; i < N; i++) {
    cout << res[i] << '\n';
  }
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