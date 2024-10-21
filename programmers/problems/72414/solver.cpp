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
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define LOCAL
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) void(0)
#endif

int Encode(char ch) { return (int) (ch - '0'); }

int Encode(const string& s) {
  const int E[] = {24, 60, 60};
  int res = 0;
  int cur = 0;
  int ptr = 0;
  for (char ch : s) {
    if (ch == ':') {
      res = res * E[ptr++] + cur;
      cur = 0; 
      continue;
    }
    cur = cur * 10 + Encode(ch);
  }
  res = res * E[ptr++] + cur;
  return res;
}

string Decode(long long x) {
  auto To2S = [](long long y) {
    string res = to_string(y);
    return string(2 - res.size(), '0') + res;
  };
  return To2S(x / 3600) + ":" + To2S(x / 60 % 60) + ":" + To2S(x % 60);
}

string solution(string play_time, string adv_time, vector<string> logs) {
  const int PLAY = Encode(play_time);
  const int AD = Encode(adv_time);
  int n = (int) logs.size();
  vector<pair<int, int>> events(n + n + 2);
  for (int i = 0; i < n; i++) {
    string s, e;
    bool first = true;
    for (char ch : logs[i]) {
      if (ch == '-') {
        first = false;
        continue;
      }
      (first ? s : e) += ch;
    }
    events[i + i] = {Encode(s), 1};
    events[i + i + 1] = {Encode(e), -1};
  }
  events[n + n] = {0, 0};
  events[n + n + 1] = {PLAY, 0};
  sort(events.begin(), events.end());
  long long best_time = 0LL;
  long long best_value = 0LL;
  {
    int L = 0;
    int R = 0;
    int balanceL = 0;
    int balanceR = 0;
    long long cur = 0LL;
    while (L < (int) events.size()) {
      if (events[L].second == 1) {
        while (R < (int) events.size() && events[R].first <= events[L].first + AD) {
          balanceR += events[R].second;
          cur -= (long long) events[R].first * events[R].second;
          R += 1;
        }
        long long cur_value = cur - (long long) a[L].first * balanceL + (long long) (a[L].first + AD) * balanceR;
        if (cur_value > best_value) {
          best_value = cur_value;
          best_time = a[L].first;
        }
      }
      balanceL += events[L].second;
      cur += (long long) events[L].first * events[L].second;
      L += 1;
    }
  }
  {
    int L = 0;
    int R = 0;
    int balanceL = 0;
    int balanceR = 0;
    long long cur = 0LL;
  }
  return Decode(best_time);
}

int main() {
  solution("02:03:55", "00:14:15", {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"});
//  solution("99:59:59",	"25:00:00",	{"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"});
//  solution("50:00:00",	"50:00:00",	{"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"});
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