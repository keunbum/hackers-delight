#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int Encode(char s[3]) {
  return ((int) (s[0] - '0')) * 12 + ((int) (s[1] - 'A'));
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  array<int, 120> mp;
  array<pair<int, int>, 60> inv;
  {
    int x = 0;
    int y = 0;
    for (int i = 0; i < 60; ++i) {
      mp[x * 12 + y] = i;
      inv[i] = {x, y};
      x = (x + 1) % 10;
      y = (y + 1) % 12;
    }
  }
  int n;
  cin >> n;
  array<array<int, 10>, 10> a;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> a[i][j];
    }
  }
  array<array<int, 12>, 12> b;
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      cin >> b[i][j];
    }
  }
  array<vector<int>, 60> c;
  for (int i = 0; i < n; ++i) {
    int x;
    char s[3];
    cin >> x >> s;
    vector<int>& v = c[mp[Encode(s)]];
    v.push_back(x);
    for (int j = (int) v.size() - 1; j > 0; --j) {
      if (v[j - 1] < v[j]) {
        swap(v[j - 1], v[j]);
      }
    }
    if ((int) v.size() > 3) {
      v.pop_back();
    }
  }
  int ans = 0;
  for (int i = 0; i < 60; ++i) {
    for (int j = i; j < 60; ++j) {
      for (int k = j; k < 60; ++k) {
        vector<pair<int, int>> groups;
        for (int x : {i, j, k}) {
          bool found = false;
          for (auto&[id, sz] : groups) {
            if (id == x) {
              found = true;
              sz += 1;
            }
          }
          if (!found) {
            groups.emplace_back(x, 1);
          }
        }
        auto[ii, iii] = inv[i];
        auto[jj, jjj] = inv[j];
        auto[kk, kkk] = inv[k];
        int sum = a[ii][jj] + b[iii][jjj]
                + a[jj][kk] + b[jjj][kkk]
                + a[kk][ii] + b[kkk][iii];
        bool ok = true;
        for (auto[id, sz] : groups) {
          if ((int) c[id].size() < sz) {
            ok = false;
            break;
          }
          for (int p = 0; p < sz; ++p) {
            sum += c[id][p];
          }
        }
        if (ok) {
          ans = max(ans, sum);
        }
      }
    }
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
  
 * stuff you should look for
  * 0-based or 1-based?
  * off-by-one error
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/