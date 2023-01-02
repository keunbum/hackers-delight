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
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    int k = n - 1;
    while (k > 0 && s[k - 1] >= s[k]) {
      k -= 1;
    }
    if (k == 0) {
      cout << "BIGGEST" << '\n';
      continue;
    }
    int min_i = -1;
    for (int p = n - 1; p >= k; p--) {
      if (s[k - 1] < s[p] && (min_i == -1 || s[p] < s[min_i])) {
        min_i = p;
      }
    }
    swap(s[k - 1], s[min_i]);
    reverse(s.begin() + k, s.end());
    cout << s << '\n';
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