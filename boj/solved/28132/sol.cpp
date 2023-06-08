#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x;
  int y;
};

string to_string(const Point& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

long long smul(Point& a, Point& b) {
  return 1LL * a.x * b.x + 1LL * a.y * b.y;
}

long long vmul(Point& a, Point& b) {
  return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool IsUpper(int x, int y) {
  return y > 0 || (y == 0 && x > 0);
}

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point> ps;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      continue;
    }
    if (IsUpper(x, y)) {
      x = -x;
      y = -y;
    }
    ps.emplace_back(x, y);
  }
  sort(ps.begin(), ps.end(), [](auto& pi, auto& pj) {
    return vmul(pi, pj) > 0LL;
  });
  int L = 0;
  int R1 = L + 1;
  int R2 = R1;
  long long m = n - (int) ps.size();
  long long ans = m * (m - 1) / 2 + m * (n - m);
  n = (int) ps.size();
  while (L < n) {
    R1 = max(R1, L + 1);
    while (R1 < n && smul(ps[L], ps[R1]) > 0LL) {
      R1 += 1;
    }
    R2 = max(R2, R1);
    while (R2 < n && smul(ps[L], ps[R2]) == 0LL) {
      R2 += 1;
    }
    ans += R2 - R1;
    L += 1;
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