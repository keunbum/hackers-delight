#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(vector<int> cards) {
  vector<bool> used(cards.size(), false);
  vector<int> groups;
  for (int ptr = 0; ptr < (int) cards.size(); ptr++) {
    if (used[ptr]) {
      continue;
    }
    int group = 0;
    while (!used[ptr]) {
      used[ptr] = true;
      ptr = cards[ptr] - 1;
      group += 1;
    }
    groups.push_back(group);
  }
  sort(groups.rbegin(), groups.rend());
  return groups[0] * (groups.size() == 1 ? 0 : groups[1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({8,6,3,7,2,5,1,4});
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