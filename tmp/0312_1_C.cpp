#include <bits/stdc++.h>

using namespace std;

string to_string(const char ch) {
  return '\'' + string(1, ch) + '\'';
}
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string(static_cast<string>(s));
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
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
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A, typename B> string to_string(pair<A, B>);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C>);
 
template <typename A>
string to_string(A v) {
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
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
void debug_out() { cout << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
 
#define LOCAL
#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) void(0)
#endif

const int md = 10000019;

void add(int& a, int b) {
  a += b;
  if (a >= md) a -= md;
}

int solution(int h, int w, vector<vector<int>> diagonals) {
  vector<vector<bool>> pass(h + 1, vector<bool>(w + 1, false));
  for (auto& v : diagonals) {
    pass[v[0]][v[1] - 1] = true;
  }
  debug(pass);
  vector<vector<vector<int>>> dp(2, vector<vector<int>>(h + 1, vector<int>(w + 1, 0)));
  dp[0][0][0] = 1;
  for (int s = 0; s < h + w; s++) {
    for (int i = 0; i <= h; i++) {
      int j = s - i;
      if (j < 0 || j >= w + 1) {
        continue;
      }
      if (i + 1 <= h) {
        add(dp[0][i + 1][j], dp[0][i][j]);
      }
      if (j + 1 <= w) {
        add(dp[0][i][j + 1], dp[0][i][j]);
      }
    }
  }
  debug(dp[0]);
  for (int s = 0; s < h + w; s++) {
    for (int i = 0; i <= h; i++) {
      int j = s - i;
      if (j < 0 || j >= w + 1) {
        continue;
      }
      if (i - 1 >= 0 && j + 1 <= w && pass[i][j]) {
        add(dp[1][i - 1][j + 1], dp[0][i][j]);
      }
      if (i + 1 <= h && j - 1 >= 0 && pass[i + 1][j - 1]) {
        add(dp[1][i + 1][j - 1], dp[0][i][j]);
      }
    }
  }
  debug(dp[1]);
  for (int s = 0; s < h + w; s++) {
    for (int i = 0; i <= h; i++) {
      int j = s - i;
      if (j < 0 || j >= w + 1) {
        continue;
      }
      if (i + 1 <= h) {
        add(dp[1][i + 1][j], dp[1][i][j]);
      }
      if (j + 1 <= w) {
        add(dp[1][i][j + 1], dp[1][i][j]);
      }
    }
  }
  debug(dp[1]);
  return dp[1][h][w];
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