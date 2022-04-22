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

  TPoint(T _x = 0, T _y = 0) : x(_x), y(_y) {}

  TPoint operator+(const TPoint& rhs) const { return TPoint(rhs.x + x, rhs.y + y); }
  TPoint operator-(const TPoint& rhs) const { return TPoint(rhs.x - x, rhs.y - y); }
  bool operator==(const TPoint& rhs) const { return x == rhs.x && y == rhs.y; }

  T abs2() const { return x * x + y * y; }

  friend T smul(const TPoint& lhs, const TPoint& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
  }
};

using Point = TPoint<long long>;

template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    vector<Point> ps(4);
    for (int i = 0; i < 4; i++) {
      cin >> ps[i].x >> ps[i].y;
    }
    debug(ps);
    bool ok = false;
    for (int i = 1; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        Point AB = ps[i] - ps[0];
        Point AD = ps[j] - ps[0];
        debug(AB, AD, smul(AB, AD));
        if (smul(AB, AD) == 0 && AB.abs2() == AD.abs2()) {
          int k = 6 - (i + j);
          if (ps[k] - ps[0] == AB + AD) {
            ok = true;
            break;
          }
        }
      }
      if (ok) break;
    }
    cout << ok << '\n';
  }
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