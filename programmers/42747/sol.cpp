#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<int> citations) {
  int low = 0;
  int high = (int) 1e4;
  while (low < high) {
    int mid = (low + high + 1) / 2;
    int cntA = 0;
    for (int x : citations) {
      cntA += (x >= mid);
    }
    if (cntA >= mid) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  return low;
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