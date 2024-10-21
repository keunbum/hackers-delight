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
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }    
  int min_paths = 0;
  {
    function<void(int, int)> Count = [&](int v, int pr) {
      int childs = 0;
      for (int u : g[v]) {
        if (u != pr) {
          Count(u, v);
          childs += 1;
        }
      }
      min_paths += childs / 2;
    };
    Count(0, -1);
    min_paths += g[0].size() % 2;
    assert(min_paths < n);
  }
  int low = 1;
  int high = n - 1;
  while (low < high) {
    int mid = (low + high) / 2;
//    debug(low, mid, high);
    vector<int> dp(n);
    function<bool(int, int)> DFS = [&](int v, int pr) {
      vector<int> to_me;
      for (int u : g[v]) {
        if (u != pr) {
          if (!DFS(u, v) || dp[u] + 1 > mid) {
            return false;
          }
          to_me.push_back(dp[u] + 1);
        }
      }
      sort(to_me.begin(), to_me.end());
//      debug(v);
//      debug(to_me);
      auto Try = [&](int b, int e) {
//        debug("Try", b, e);
        while (b < e) {
          if (to_me[b] + to_me[e] > mid) {
            return false;
          }
          ++b;
          --e;
        }
        dp[v] = 0;
        return true;
      };
      auto Find = [&](int b, int e) {
        multiset<int, greater<int>> s;
        for (int i = b; i <= e; i++) {
          s.insert(to_me[i]);
        }
        int picked = -1;
        vector<int> xs;
        for (int rot = 0; rot < 2; rot++) {
          bool found = true;
//          debug(rot, s);
          while ((int) s.size() > 1 - rot) {
            int x = *s.begin();
            s.erase(s.begin());
            auto it = s.lower_bound(mid - x);
            if (it == s.end()) {
              found = false;
              picked = x;
              break;
            }
//            debug(x, *it);
            assert(x + *it <= mid);
            s.erase(it);
          }
          if (found) {
            dp[v] = rot == 0 ? *s.begin() : picked;
//            debug("Find true", rot, dp[v]);
            return true;
          }
        }
//        debug("Find false");
        return false;
      };
      int sz = (int) to_me.size();
      bool even = sz % 2 == 0;
      return (even && (Try(0, sz - 1) || (v != 0 && Find(0, sz - 2)))) || (!even && Find(0, sz - 1));
    };
    if (DFS(0, -1)) {
      high = mid;
//      debug("ok");
    } else {
      low = mid + 1;
//      debug("not ok");
    }
//    debug(dp);
  }
  cout << min_paths << " " << low << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/