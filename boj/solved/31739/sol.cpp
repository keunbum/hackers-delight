#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, k, hp, p;
  cin >> h >> w >> k >> hp >> p;
  vector<int> x(k), y(k), s(k);
  for (int i = 0; i < k; ++i) {
    cin >> x[i] >> y[i] >> s[i];
    --x[i]; --y[i];
  }
  int max_a = 0;
  vector<int> perm(k);
  iota(perm.begin(), perm.end(), 0);
  do {
    int cnt = 1;
    int chp = hp;
    for (int pos = 0; pos < k - 1; ++pos) {
      int i = perm[pos];
      int j = perm[pos + 1];
      chp -= abs(x[i] - x[j]) + abs(y[i] - y[j]);
      if (chp < 0) {
        break;
      }
      cnt += 1;
    }
    max_a = max(max_a, cnt);
  } while (next_permutation(perm.begin(), perm.end()));
  int max_b = 0;
  for (int cx = 0; cx < h; ++cx) {
    for (int cy = 0; cy < w; ++cy) {
      int cnt = 0;
      for (int i = 0; i < k; ++i) {
        if (p >= (abs(x[i] - cx) + abs(y[i] - cy)) * s[i]) {
          cnt += 1;
        }
      }
      max_b = max(max_b, cnt);
    }
  }
  cout << max_a << " " << max_b << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * Do I have to solve like this?
  
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