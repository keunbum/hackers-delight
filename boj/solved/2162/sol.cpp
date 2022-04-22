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

using Point = TPoint<long long>;

template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

bool LiesOnInside(const Point& a, const Point& b, const Point& p) {
  return smul(p - a, p - b) <= 0;
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
    if ((long long) z1 * z2 > 0) {
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
    if ((long long) z1 * z2 > 0) {
      return false;
    }
    if (z1 == 0 && z2 == 0) {
      return (LiesOnInside(a, b, c) || LiesOnInside(a, b, d) || LiesOnInside(c, d, a) || LiesOnInside(c, d, b));
    }
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
//    assert(!(a[i].x == b[i].x && a[i].y == b[i].y));
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  function<int(int)> Get = [&](int x) {
    return x == p[x] ? x : (p[x] = Get(p[x]));
  };
  int group_cnt = n;
  int max_group_size = 1;
  vector<int> sz(n, 1);
  auto Unite = [&](int i, int j) {
    i = Get(i);
    j = Get(j);
    if (i != j) {
      sz[i] += sz[j];
      p[j] = i;
      group_cnt -= 1;
      max_group_size = max(max_group_size, sz[i]);
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (Intersect(a[i], b[i], a[j], b[j])) {
        debug(true);
        Unite(i, j);
      }
    }
  }
  debug(p);
  debug(sz);
  cout << group_cnt << "\n" << max_group_size << '\n';
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