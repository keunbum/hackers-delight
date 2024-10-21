#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

#define N 200000

int p[N], sz[N];

inline int Get(int x) {
  while (x != p[x]) {
    x = p[x] = p[p[x]];
  }
  return x;
}

unordered_map<string, int> mp;

inline int GetID(const string& s) {
  return mp.emplace(s, (int) mp.size()).first->second;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    for (int i = 0; i < N; ++i) {
      p[i] = i;
      sz[i] = 1;
    }
    int m;
    cin >> m;
    while (m--) {
      char a[21], b[21];
      cin >> a >> b;
      int x = Get(GetID(string(a)));
      int y = Get(GetID(string(b)));
      if (x != y) {
        p[x] = y;
        sz[y] += sz[x];
      }
      cout << sz[y] << '\n';
    }
    unordered_map<string, int>().swap(mp);
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