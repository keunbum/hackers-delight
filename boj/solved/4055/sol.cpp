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
  int qq = 1;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      break;
    }
    vector<vector<bool>> aux(48, vector<bool>(n, false));
    vector<int> es(n);
    for (int i = 0; i < n; i++) {
      int s, e;
      cin >> s >> e;
      es[i] = e;
      s <<= 1;
      e <<= 1;
      while (s < e) {
        aux[s][i] = 1;
        s += 1;
      }
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return es[i] < es[j];
    });
    vector<bool> used(n, false);
    for (int i = 16; i < 48; i++) {
      for (int j : order) {
        if (aux[i][j] && !used[j]) {
          used[j] = true;
          break;
        }
      }
    }
    cout << "On day " << qq << " Emma can attend as many as " << count(used.begin(), used.end(), true) << " parties." << '\n';
    qq += 1;
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
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