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

  TPoint() : x{}, y{}, z{} {}
  TPoint(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {}

  TPoint operator+(const TPoint& rhs) const { return TPoint(x + rhs.x, y + rhs.y, z + rhs.z); }
  TPoint operator-(const TPoint& rhs) const { return TPoint(x - rhs.x, y - rhs.y, z - rhs.z); }
  TPoint operator*(const T& rhs) const { return TPoint(x * rhs, y * rhs, z * rhs); }

  T abs2() const { return x * x + y * y + z * z; }

};

using Point = TPoint<long double>;

template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ", " + to_string(p.z) + ")";
}

template <typename T>
istream& operator>>(istream& in, TPoint<T>& p) {
  return in >> p.x >> p.y >> p.z;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  constexpr long double eps = 1e-9;
  Point A, B, C;
  cin >> A >> B >> C;
  Point L = A;
  Point R = B;
  for (int iter = 0; iter < 300; iter++) {
    Point M1 = L * (2.0 / 3) + R * (1.0 / 3);
    Point M2 = L * (1.0 / 3) + R * (2.0 / 3);
    debug(L, M1, M2, R);
    if ((C - M1).abs2() - (C - L).abs2() > eps) {
      debug(1);
      R = M1;
    } else
    if ((C - M2).abs2() - (C - R).abs2() > eps) {
      debug(2);
      L = M2;
    } else
    if ((C - M2).abs2() - (C - M1).abs2() > eps) {
      debug(3);
      L = M1;
    } else
    if ((C - M1).abs2() - (C - M2).abs2() > eps) {
      debug(4);
      R = M2;
    } else {
      debug(5);
      L = M1;
      R = M2;
    }  
  }
  cout << fixed << setprecision(17) << sqrt((C - L).abs2()) << '\n';
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