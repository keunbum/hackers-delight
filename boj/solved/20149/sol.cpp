#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

template <typename T>
struct TPoint {
  T x;
  T y;

  TPoint(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}

  TPoint operator-(const TPoint& rhs) const { return TPoint(x - rhs.x, y - rhs.y); }

  friend T smul(const TPoint& a, const TPoint& b) {
    return a.x * b.x + a.y * b.y;
  }
};

using Point = TPoint<long long>;

bool Intersect(Point a, Point b, Point c, Point d, double& x, double& y) {
  long long A1 = a.y - b.y;
  long long B1 = b.x - a.x;
  long long C1 = -A1 * a.x - B1 * a.y;
  long long z1 = A1 * c.x + B1 * c.y + C1;
  long long z2 = A1 * d.x + B1 * d.y + C1;
  if ((z1 < 0 && z2 < 0) || (z1 > 0 && z2 > 0)) {
    return false;
  }
  long long A2 = c.y - d.y;
  long long B2 = d.x - c.x;
  long long C2 = -A2 * c.x - B2 * c.y;
  z1 = A2 * a.x + B2 * a.y + C2;
  z2 = A2 * b.x + B2 * b.y + C2;
  if ((z1 < 0 && z2 < 0) || (z1 > 0 && z2 > 0)) {
    return false;
  }
  if (z1 == 0 && z2 == 0) {
    long long xa = a.x;
    long long xb = b.x;
    long long xc = c.x;
    long long xd = d.x;
    if (xa > xb) {
      swap(xa, xb);
    }
    if (xc > xd) {
      swap(xc, xd);
    }
    if (xa > xd || xb < xc) {
      return false;
    }
    xa = a.y;
    xb = b.y;
    xc = c.y;
    xd = d.y;
    if (xa > xb) {
      swap(xa, xb);
    }
    if (xc > xd) {
      swap(xc, xd);
    }
    if (xa > xd || xb < xc) {
      return false;
    }
    long long s1 = smul(a - c, a - d);
    long long s2 = smul(b - c, b - d);
    long long s3 = smul(c - a, c - b);
    long long s4 = smul(d - a, d - b);
    if (((s1 > 0 && s2 == 0) || (s1 == 0 && s2 > 0)) && ((s3 > 0 && s4 == 0) || (s3 == 0 && s4 > 0))) {
      if (s1 == 0) {
        x = a.x;
        y = a.y;
      } else {
        x = b.x;
        y = b.y;
      }
    }
    return true;
  }
  if (A1 == 0) {
    assert(A2 != 0);
    y = (double) -C1/ B1;
    x = -(B2 * y + C2) / (double) A2;
    return true;
  }
  if (A2 == 0) {
    assert(A1 != 0);
    y = (double) -C2 / B2;
    x = -(B1 * y + C1) / (double) A1;
    return true;
  }
  if (B1 == 0) {
    assert(B2 != 0);
    x = (double) -C1 / A1;
    y = -(A2 * x + C2) / (double) B2;
    return true;
  }
  if (B2 == 0) {
    assert(B1 != 0);
    x = (double) -C2 / A2;
    y = -(A1 * x + C1) / (double) B1;
    return true;
  }
  assert(A1 * B2 - A2 * B1 != 0);
  x = (double) -(C1 * B2 - C2 * B1) / (double) (A1 * B2 - A2 * B1);
  y = (double) -(A1 * x + C1) / (double) B1;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const double inf = 1e9;
  Point a, b, c, d;
  cin >> a.x >> a.y >> b.x >> b.y;
  cin >> c.x >> c.y >> d.x >> d.y;
  double x = inf;
  double y = inf;
  if (Intersect(a, b, c, d, x, y)) {
    cout << 1 << '\n';
    if (x != inf) {
      assert(abs(x) < inf && abs(y) < inf);
      cout << fixed << setprecision(17) << x << " " << y << '\n';
    }
    return 0;
  } 
  cout << 0 << '\n';
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