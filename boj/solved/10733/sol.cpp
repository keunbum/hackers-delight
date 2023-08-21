#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<int> Get(int x) {
  vector<int> ret{x};
  set<int> s{x};
  while (true) {
    int y = 0;
    while (x > 0) {
      y += (x % 10) * (x % 10);
      x /= 10;
    }
    if (!s.insert(y).second) {
      break;
    }
    ret.push_back(y);
    x = y;
  }
  return ret;
}

vector<int> GetSorted(vector<int>& a) {
  vector<int> perm(a.size());
  iota(perm.begin(), perm.end(), 0);
  sort(perm.begin(), perm.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  return perm;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int a, b;
    cin >> a >> b;
    if (a + b == 0) {
      break;
    }
    cout << a << ' ' << b << ' ';
    auto x = Get(a);
    auto y = Get(b);
    auto permX = GetSorted(x);
    auto permY = GetSorted(y);
    int i = 0;
    int j = 0;
    vector<array<int, 2>> aux;
    while (i < (int) permX.size() && j < (int) permY.size()) {
      int id = permX[i];
      int jd = permY[j];
      if (x[id] == y[jd]) {
        aux.push_back({id, jd});
        i += 1;
        j += 1;
      } else
      if (x[id] < y[jd]) {
        i += 1;
      } else {
        j += 1;
      }
    }
    if (aux.empty()) {
      cout << 0 << '\n';
      continue;
    }
    auto res = *min_element(aux.begin(), aux.end(), [](auto& ai, auto& aj) {
      return ai[0] + ai[1] < aj[0] + aj[1];
    });
    cout << (res[0] + res[1] + 2) << '\n';
  }
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