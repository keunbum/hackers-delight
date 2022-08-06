#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int solution(int cacheSize, vector<string> cities) {
  debug(cacheSize, cities);
  if (cacheSize == 0) {
    return 5 * (int) cities.size();
  }
  vector<int> last(cacheSize, -1);
  vector<string> cache(cacheSize);
  int ret = 0;
  for (int i = 0; i < (int) cities.size(); i++) {
    for (char& ch : cities[i]) {
      ch |= 32;
    }
    debug(cities[i]);
    int p = (int) (find(cache.begin(), cache.end(), cities[i]) - cache.begin());
    if (p == cacheSize) {
      p = (int) (min_element(last.begin(), last.end()) - last.begin());
    }
    debug(cities[i], p, cache[p]);
    ret += (cache[p] == cities[i] ? 1 : 5);
    last[p] = i;
    cache[p] = cities[i];
  } 
  debug(ret);
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution(3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"});
  solution(3, {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"});
  solution(2, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"});
  solution(5, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"});
  solution(2, {"Jeju", "Pangyo", "NewYork", "newyork"});
  solution(0, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"}	);
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