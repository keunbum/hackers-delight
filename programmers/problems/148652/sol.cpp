#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

// total: [0, 5^n)
int solution(int n, long long l, long long r) {
  long long p5[21];
  p5[0] = 1;
  for (int i = 0; i < 20; ++i) {
    p5[i + 1] = p5[i] * 5;
  }
  cerr << n << " " << l << " " << r << '\n';
  // [s, e)
  auto DFS = [&](auto&& self, int s, int e) -> int {
    int m1 = -1, m2 = -1;
    for (int i = 0; i < 5; ++i) {
      if (l < i * p5[n - 1]) {
        m1 = i * p5[n - 1];
        break;
      }
    }
    for (int i = 4; i >= 0; --i) {
      if (i * p5[n - 1] < r) {
        m2 = i * p5[n - 1];
        break;
      }
    }
    cerr << s << " " << m1 << " " << m2 << " " << r << '\n';
    return self(self, s, m1) + self(self, m1, m2) + self(self, m2, e);
  };
  long long m = 1;
  for (int i = 0; i < n; ++i) {
      m *= 5;
  }
  return DFS(DFS, 0, m);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cerr << solution(2, 4, 17) << '\n';
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
