#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool>& v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N>& v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A& v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C>& p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D>& p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, rot;
  cin >> h >> w >> rot;
  vector<vector<int>> a(h, vector<int>(w));
  int si = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      if (si == -1 && a[i][j] == -1) {
        si = i;
      }
    }
  }
//  debug(a);
  for (int _ = 0; _ < rot; _++) {
    vector<vector<int>> b = a;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int foo = a[i][j];
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            if (di * di + dj * dj == 1) {
              int ni = i + di;
              int nj = j + dj;
              if (ni >= 0 && nj >= 0 && ni < h && nj < w && a[ni][nj] != -1) {
                int bar = foo / 5;
                b[ni][nj] += bar;
                b[i][j] -= bar;
              }
            }
          }
        }
      }
    }
    swap(a, b);
//    debug(a);
    {
      for (int i = si - 2; i >= 0; i--) a[i + 1][0] = a[i][0];
      for (int j = 1; j < w; j++) a[0][j - 1] = a[0][j];
      for (int i = 1; i <= si; i++) a[i - 1][w - 1] = a[i][w - 1];
      for (int j = w - 2; j >= 1; j--) a[si][j + 1] = a[si][j];
      a[si][1] = 0;
    }
    {
      for (int i = si + 3; i < h; i++) a[i - 1][0] = a[i][0];
      for (int j = 1; j < w; j++) a[h - 1][j - 1] = a[h - 1][j];
      for (int i = h - 2; i >= si + 1; i--) a[i + 1][w - 1] = a[i][w - 1];
      for (int j = w - 2; j >= 1; j--) a[si + 1][j + 1] = a[si + 1][j];
      a[si + 1][1] = 0;
    }
//    debug(a);
  }
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] != -1) {
        ans += a[i][j];
      }
    }
  }
  cout << ans << '\n';
  return 0;
}