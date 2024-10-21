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
  double T;
  int n;
  cin >> T >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int min_cut = 500;
  for (int i = 0; i < n; i++) {
    for (int aux_cut = 0; aux_cut < min_cut; aux_cut++) {
      double cur_max = 1.0 * a[i] / (aux_cut + 1);
      double cur_min = T * cur_max;
      bool ok = true;
      int cuts = 0;
      for (int j = 0; j < n; j++) {
        int cut = (a[j] - 1) / cur_max;
        cuts += cut;
        double piece = 1.0 * a[j] / (cut + 1);
        if (piece < cur_min || cuts >= 500) {
          ok = false;
          break;
        }
      }
      if (ok) {
        min_cut = min(min_cut, cuts);
        break;
      }
    }
  }
  assert(min_cut < 500);
  cout << min_cut << '\n';
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
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/