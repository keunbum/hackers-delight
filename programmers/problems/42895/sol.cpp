#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int N, int number) {
  array<long long, 10> Ns;
  Ns[0] = 0;
  for (int i = 0; i < 9; i++) {
    Ns[i + 1] = Ns[i] * 10 + N;
    Push(que, Ns[i + 1], i + 1);
  }
  function<int(int)> DFS = [&](int x) {
    for (int i = 1; i <= 9; i++) {
      for (int nx : {x + Ns[i], x - Ns[i], x * Ns[i], x / Ns[i]}) {
        
  };
  return DFS(number);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution(5, 31168);
//  solution(5, 12);
//  solution(2, 11);
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