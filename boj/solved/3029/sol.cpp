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
  auto Read = [&]() {
    string s;
    cin >> s;
    int x = stoi(s.substr(0, 2));
    int y = stoi(s.substr(3, 2));
    int z = stoi(s.substr(6, 2));
    return x * 3600 + y * 60 + z;
  };
  auto Decode = [&](int t) -> string {
    int x = t / 3600;
    int y = (t % 3600) / 60;
    int z = t % 60;
    if (x + y + z == 0) {
      x = 24;
    }
    auto F = [](int x) {
      string s = to_string(x);
      return (s.size() == 1 ? "0" : "") + s;
    };
    return F(x) + ":" + F(y) + ":" + F(z);
  };
  int a = Read();
  int b = Read();                
  const int md = 23 * 3600 + 59 * 60 + 59 + 1;
  cout << Decode((b - a + md) % md) << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * keep calm
  
 * stuff you should look for
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