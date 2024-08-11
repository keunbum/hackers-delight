#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int solution(vector<string> friends, vector<string> gifts) {
  sort(friends.begin(), friends.end());
  int n = int(friends.size());
  vector<vector<int>> a(n, vector<int>(n, 0));
  vector<int> b(n, 0);
  for (string& str : gifts) {
    istringstream sin(str);
    string from, to;
    sin >> from >> to;
    int i = int(lower_bound(friends.begin(), friends.end(), from) - friends.begin());
    int j = int(lower_bound(friends.begin(), friends.end(), to) - friends.begin());
    a[i][j] += 1;
    b[i] += 1;
    b[j] -= 1;
  }
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (int j = 0; j < n; ++j) {
      if (a[i][j] > a[j][i] || (a[i][j] == a[j][i] && b[i] > b[j])) {
        cur += 1;
      }
    }
    ret = max(ret, cur);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({"muzi", "ryan", "frodo", "neo"}, {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"});
  solution({"joy", "brad", "alessandro", "conan", "david"},	{"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"});
  solution({"a", "b", "c"},	{"a b", "b a", "c a", "a c", "a c", "c a"});
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * Do I have to solve like this?
  
 * stuff you should look for
  * 0-based or 1-based?
  * off-by-one error
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/
