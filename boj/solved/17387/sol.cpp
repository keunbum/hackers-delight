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
};

using Point = TPoint<long long>;

template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

bool Intersect(const Point& a, const Point& b, const Point& c, const Point& d) {
  debug(a, b, c, d);
  {
    long long A = a.y - b.y;
    long long B = b.x - a.x;
    long long C = -A * a.x - B * a.y;
    long long z1 = A * c.x + B * c.y + C;
    long long z2 = A * d.x + B * d.y + C;
    debug(A, B, C, z1, z2);
    if ((z1 < 0 && z2 < 0) || (z1 > 0 && z2 > 0)) {
      return false;
    }
  } 
  {
    long long A = c.y - d.y;
    long long B = d.x - c.x;
    long long C = -A * c.x - B * c.y;
    long long z1 = A * a.x + B * a.y + C;
    long long z2 = A * b.x + B * b.y + C;
    debug(A, B, C, z1, z2);
    if ((z1 < 0 && z2 < 0) || (z1 > 0 && z2 > 0)) {
      return false;
    }
    if (z1 == 0 && z2 == 0) {
      {
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
        if (xb < xc || xd < xa) {
          return false;
        }
      }
      {
        long long ya = a.y;
        long long yb = b.y;
        long long yc = c.y;
        long long yd = d.y;
        if (ya > yb) {
          swap(ya, yb);
        }
        if (yc > yd) {
          swap(yc, yd);
        }
        if (yb < yc || yd < ya) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Point a, b, c, d;
  cin >> a.x >> a.y >> b.x >> b.y;
  cin >> c.x >> c.y >> d.x >> d.y;
  cout << Intersect(a, b, c, d) << '\n';
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