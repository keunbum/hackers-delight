#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<int> topping) {
  auto Add = [&](vector<int>&cnt, int& kinds, int x) {
    kinds += ++cnt[x] == 1;
  };
  auto Remove = [&](vector<int>&cnt, int& kinds, int x) {
    kinds -= --cnt[x] == 0;
  };
  const int MAX = (int) 1e4;
  int A = 0;
  int B = 0;
  vector<int> a(MAX + 1, 0);
  vector<int> b(MAX + 1, 0);
  for (int x : topping) {
    Add(b, B, x);
  };
  int ret = 0;
  for (int x : topping) {
    ret += A == B;
    Add(a, A, x);
    Remove(b, B, x);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
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
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(PERSPECTIVE) (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/