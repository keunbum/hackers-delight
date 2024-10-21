#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
  vector<int> twoSum(vector<int> a, int x) {
    int n = (int) a.size();
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
      b[i] = make_pair(a[i], i);
    }
    sort(b.begin(), b.end());
    int L = 0;
    int R = n - 1;
    while (true) {
      int y = b[L].first + b[R].first;
      if (y == x) {
        break;
      }
      y < x ? ++L : --R;
    }
    return {b[L].second, b[R].second};
  }
};

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to their limitations
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. keep calm
  
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
*/