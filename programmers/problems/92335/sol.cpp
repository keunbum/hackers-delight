#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

bool IsPrime(long long x) {
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int solution(int n, int k) {
  string s;
  while (n > 0) {
    s += (char) (n % k) + '0';
    n /= k;
  }
  reverse(s.begin(), s.end());
  s += '0';
  long long val = 0;
  int ret = 0;
  for (char ch : s) {
    if (ch == '0') {
      ret += (val > 1) && IsPrime(val);
      val = 0;
      continue;
    }
    val = val * 10 + (int) (ch - '0');
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