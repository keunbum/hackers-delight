#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
  map<string, int> mp;
  int n = (int) enroll.size();
  mp["-"] = n;
  vector<int> p(n + 1, -1);
  for (int i = 0; i < n; i++) {
    mp[enroll[i]] = i;
    int j = mp[referral[i]];
    p[i] = j;
  }
  vector<int> ret(n + 1, 0);
  for (int i = 0; i < (int) seller.size(); i++) {
    int id = mp[seller[i]];
    int val = amount[i] * 100;
    while (p[id] != -1 && val > 0) {
      ret[id] += val - val / 10;
      val /= 10;
      id = p[id];
    }
  }
  debug(ret);
  ret.resize(n);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto res = solution({"john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"}, {"-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"}, {"young", "john", "tod", "emily", "mary"}, {12, 4, 2, 5, 10});
  debug(res);
//  auto res = solution({"E", "D", "C", "B", "A"}, {"-", "E", "E", "D", "C"}, {"A", "B"}, {9, 10});
//  debug(res);
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