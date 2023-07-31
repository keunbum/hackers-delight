#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) void(0)
#endif

struct Event {
  int x;
  int y;
  int i;

  Event(int x, int y, int i) : x(x), y(y), i(i) {}

  inline bool operator<(const Event& rhs) {
    if (x != rhs.x) {
      return x < rhs.x;
    }
    return y > rhs.y;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<Event> events;
  vector<bool> used(m, true);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    if (x < y) {
      events.emplace_back(x, y, i);
      events.emplace_back(x + n, y + n, i);
    } else {
      events.emplace_back(x, y + n, i);
    }
  }
  sort(events.begin(), events.end());
  int mx = -1;
  int sz = (int) events.size();
  for (int i = 0; i < sz; ++i) {
    auto& e = events[i];
    used[e.i] = used[e.i] && (e.y > mx);
    mx = max(mx, e.y);
  }
  for (int i = 0; i < m; ++i) {
    if (used[i]) {
      cout << i + 1 << ' ';
    }
  }
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