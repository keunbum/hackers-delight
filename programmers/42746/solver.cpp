#include <bits/stdc++.h>

using namespace std;

const int P[] = {1, 10, 100, 1000, 10000};

string solution(vector<int> a) {
  vector<int> L(1001);
  L[0] = 1;
  for (int i = 1; i < 1001; i++) {
    int t = i;
    while (t > 0) {
      L[i] += 1;
      t /= 10;
    }
  }
  sort(a.begin(), a.end(), [&](int x, int y) {
    return x * P[L[y]] + y > y * P[L[x]] + x;
  });
  string ret;
  for (int x : a) {
    for (int i = L[x] - 1; i >= 0; i--) {
      ret += (char) (x / P[i] % 10 + '0');
    }
  }
  return (ret[0] == '0' ? "0" : ret);
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