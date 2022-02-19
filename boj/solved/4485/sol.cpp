#include <bits/stdc++.h>

using namespace std;

using tiii = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int qq = 1; ; qq++) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    struct St {
      bool operator()(const tiii& ti, const tiii& tj) { return get<0>(ti) > get<0>(tj); }
    };
    priority_queue<tiii, vector<tiii>, St> s;
    const int inf = (int) 1e9;
    vector<vector<int>> dist(n, vector<int>(n, inf));
    dist[0][0] = a[0][0];
    s.emplace(dist[0][0], 0, 0);
    while (!s.empty()) {
      auto[expec, i, j] = s.top();
      s.pop();
      if (expec != dist[i][j]) {
        continue;
      }
      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          if (di * di + dj * dj == 1) {
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && nj >= 0 && ni < n && nj < n && dist[i][j] + a[ni][nj] < dist[ni][nj]) {
              dist[ni][nj] = dist[i][j] + a[ni][nj];
              s.emplace(dist[ni][nj], ni, nj);
            }
          }
        }
      }
    }
    cout << "Problem " << qq << ": " << dist[n - 1][n - 1] << '\n';
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