#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

vector<int> solution(vector<string> names, vector<int> yearnings, vector<vector<string>> photos) {
  vector<int> order(names.size(), 0);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return names[i] < names[j];
  });
  vector<int> ret(photos.size(), 0);
  for (int id = 0; id < (int) photos.size(); ++id) {
    for (auto& str : photos[id]) {
      int low = 0;
      int high = (int) order.size() - 1;
      while (low < high) {
        int mid = (low + high) >> 1;
        if (names[order[mid]] < str) {
          low = mid + 1;
        } else {
          high = mid;
        }
      } 
      if (names[order[low]] == str) {
        ret[id] += yearnings[order[low]];
      }
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({"may", "kein", "kain", "radi"}, {5, 10, 1, 3}, {{"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}});
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  
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