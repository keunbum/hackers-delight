#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> GetSorted(const vector<vector<int>>& a) {
  vector<vector<int>> new_a;
  for (int i = 0; i < (int) a.size(); i++) {
    map<int, int> mp;
    for (int j = 0; j < (int) a[i].size(); j++) {
      if (a[i][j] == 0) {
        continue;
      }
      mp[a[i][j]] += 1;
    }
    vector<pair<int, int>> ps;
    for (auto[x, y] : mp) {
      if (y > 0) {
        ps.emplace_back(x, y);
      }
    }
    sort(ps.begin(), ps.end(), [](const pair<int, int>& pi, const pair<int, int>& pj) {
      return pi.second < pj.second || (pi.second == pj.second && pi.first < pj.first);
    });
    vector<int> v;
    for (auto[x, y] : ps) {
      v.push_back(x);
      v.push_back(y);
    }
    v.resize(min(100, (int) v.size()));
    new_a.push_back(v);
  }
  return new_a;
}

vector<vector<int>> GetInv(const vector<vector<int>>& a) {
  vector<vector<int>> b;
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) a[i].size(); j++) {
      while (j >= (int) b.size()) {
        b.push_back(vector<int>());
      }
      while (i >= (int) b[j].size()) {
        b[j].push_back(0);
      }
      b[j][i] = a[i][j];
    }
  }
  return b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, c, k;
  cin >> r >> c >> k;
  --r; --c;
  vector<vector<int>> a(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  for (int iter = 0; iter <= 100; iter++) {
      /*cerr << "iter: " << iter << endl;
      for (int i = 0; i < (int) a.size(); i++) {
        for (int j = 0; j < (int) a[i].size(); j++) {
          if (j > 0) {
            cerr << " ";
          }
          cerr << a[i][j];
        }
        cerr << endl;
      }
      cerr << endl;*/
    if (r < (int) a.size() && c < (int) a[r].size() && a[r][c] == k) {
      cout << iter << '\n';
      return 0;
    }
    int maxR = (int) a.size();
    int maxC = (int) (*max_element(a.begin(), a.end(), [](const vector<int>& v, const vector<int>& u) {
      return v.size() < u.size();
    })).size();
    if (maxR >= maxC) {
      a = GetSorted(a);
    } else {
      a = GetInv(GetSorted(GetInv(a)));
    }
  }
  cout << -1 << '\n';
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