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
  T z;

  TPoint(T _x = 0, T _y = 0, T _z = 0) : x(_x), y(_y), z(_z) {}

  TPoint operator-(const TPoint& rhs) const {
    return TPoint(x - rhs.x, y - rhs.y, z - rhs.z);
  }

  TPoint operator*(const TPoint& rhs) const {
    return TPoint(y * rhs.z - z * rhs.y, -(x * rhs.z - z * rhs.x), x * rhs.y - y * rhs.x);
  }

  friend T smul(const TPoint& a, const TPoint& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }

  T abs2() const {
    return x * x + y * y + z * z;
  }
};

using Point = TPoint<long long>;

template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ", " + to_string(p.z) + ")";
}

long long GetZ(Point a, Point n, Point p) {
  return n.x * p.x + n.y * p.y + n.z * p.z - smul(a, n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(17);
  Point A, B, C;
  cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;
  debug(A, B, C);
  if (((C - A) * (C - B)).abs2() == 0) {
    debug("lies on line");
    if (smul(C - A, C - B) <= 0) {
      debug("lies on segment");
      cout << 0 << '\n';
    } else {
      debug("out of segment");
      cout << sqrt(min((C - A).abs2(), (C - B).abs2())) << '\n';
    }
    return 0;
  }
  long long z1 = GetZ(A, B - A, C);
  long long z2 = GetZ(B, B - A, C);
  if (z1 == 0 || z2 == 0 || (z1 > 0 && z2 < 0) || (z1 < 0 && z2 > 0)) {
    debug("H lies on segment");
    cout << sqrt(((C - A) * (C - B)).abs2()) / sqrt((A - B).abs2()) << '\n';
    return 0;
  }
  debug("H doesn't lies on segment");
  cout << sqrt(min((C - A).abs2(), (C - B).abs2())) << '\n';
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