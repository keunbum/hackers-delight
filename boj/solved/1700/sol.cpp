#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(k);         
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    --a[i];        
  }         
  int ans = 0;
  vector<int> b;
  auto GetFirstFrom = [&](int i, int x) {
    int j;
    for (j = i; j < k; j++) {
      if (a[j] == x) {
        break;
      }
    }
    return j;
  };
  for (int i = 0; i < k; i++) {
    if (find(b.begin(), b.end(), a[i]) != b.end()) {
      continue;
    }
    if ((int) b.size() < n) {
      b.push_back(a[i]);
      continue;
    }
    auto it = min_element(b.begin(), b.end(), [&](int bi, int bj) {
      return GetFirstFrom(i, bi) > GetFirstFrom(i, bj);
    });
    b.erase(it);
    b.push_back(a[i]);
    ans += 1;
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