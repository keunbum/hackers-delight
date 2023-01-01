#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int d;
    string s;
    cin >> s >> d;
    auto Encode = [](string s) {
      int hh = stoi(s.substr(0, 2));
      int mm = stoi(s.substr(3, 2));
      return hh * 60 + mm;
    };
    auto Calc = [](int h) {
      return (h + 59) / 60 * 1000;
    };
    int st = Encode(s) + 1440;
    int en = st + d;
    const int MAX = (int) 1e4;
    vector<int> sum(MAX + 1, 0);
    for (int i = 0; i < d; i++) {
      sum[st + i + 1] += 1;
    }
    for (int i = 0; i < MAX; i++) {
      sum[i + 1] += sum[i];
    }
    int ans = 0;
    int beg = st;
    for (int it = 0; it < 5; it++) {
      int T1 = it * 1440 + Encode("22:00");
      int T2 = (it + 1) * 1440 + Encode("08:00");
      int night_hour = sum[T2] - sum[T1];
      if (night_hour <= 300) {
      } else {
        ans += Calc(sum[T1] - sum[beg]) + 5000;
        beg = T2;
      }
    }
    ans += Calc(sum[en] - sum[beg]);
    cout << ans << '\n';
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/