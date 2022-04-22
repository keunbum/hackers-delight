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

  friend T vmul(const TPoint& a, const TPoint& b) {
    return a.x * b.y - a.y * b.x;
  }
};

using Point = TPoint<int>;

template <typename T>
string to_string(TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

bool LiesOnSegment(Point a, Point b, Point p) {
  debug("LOS", a, b, p);
  return (vmul(p - a, p - b) == 0 && smul(p - a, p - b) <= 0);
}

bool LiesOnBoundary(Point a, Point b, Point p) {
  return (LiesOnSegment(a, Point(a.x, b.y), p)
   || LiesOnSegment(a, Point(b.x, a.y), p)
   || LiesOnSegment(b, Point(a.x, b.y), p)
   || LiesOnSegment(b, Point(b.x, a.y), p)
  );
}

bool Intersect(Point a, Point b, Point c, Point d) {
  int xa = a.x;
  int ya = a.y;
  int xb = b.x;
  int yb = b.y;
  int xc = c.x;
  int yc = c.y;
  int xd = d.x;
  int yd = d.y;
  if (xa > xd || xb < xc || ya > yd || yb < yc) {
    return false;
  }       
  if ((xa < xc && xd < xb && ya < yc && yd < yb) 
   || (xc < xa && xb < xd && yc < ya && yb < yd)) {
    return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> Get = [&](int x) {
    return x == p[x] ? x : (p[x] = Get(p[x]));
  };
  int group_cnt = n;
  auto Unite = [&](int i, int j) {
    i = Get(i);
    j = Get(j);
    if (i != j) {
      p[j] = i;
      group_cnt -= 1;
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      debug(i, j, a[i], b[i], a[j], b[j]);
      if (Intersect(a[i], b[i], a[j], b[j])) {
        debug("intersect");
        Unite(i, j);
      }
    }
  }
  int ans = group_cnt;
  for (int i = 0; i < n; i++) {
    const Point origin = Point(0, 0);
    if (LiesOnBoundary(a[i], b[i], origin)) {
      debug("met already");
      ans -= 1;
      break;
    }
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