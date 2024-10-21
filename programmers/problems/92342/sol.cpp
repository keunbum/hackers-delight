#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int S = 11;

bool Cmp(const vector<int>& a, const vector<int>& b) {
  for (int i = S - 1; i >= 0; i--) {
    if (a[i] > 0 && b[i] > 0) {
      return a[i] < b[i];
    }
    if (a[i] > 0) {
      return false;
    }
    if (b[i] > 0) {
      return true;
    }
  }
  assert(false);
  return false;
}
vector<int> solution(int n, vector<int> info) {
  vector<int> best;
  int best_diff = 0;
  for (int t = 1; t < (1 << S); t++) {
    int me = 0;
    int him = 0;
    int chance = n;
    bool ok = true;
    vector<int> aux;
    for (int i = 0; i < S; i++) {
      if ((t >> i) & 1) {
        int need = info[i] + 1;
        if (chance < need) {
          ok = false;
          break;
        }
        chance -= need;
        me += 10 - i;
        aux.push_back(need);
      } else {
        if (info[i] > 0) {
          him += 10 - i;
        }
        aux.push_back(0);
      }
    }
    if (!ok || me <= him) {
      continue;
    }
    if (chance > 0) {
      for (int i = S - 1; i >= 0; i--) {
        if (((t >> i) & 1) == 0) {
          aux[i] = chance;
          break;
        }
      }
    }
    debug(bitset<S>(t), him, me, aux);
    assert(aux.size() == S && accumulate(aux.begin(), aux.end(), 0) == n);
    if (me - him > best_diff || (me - him == best_diff && Cmp(best, aux))) {
      best_diff = me - him;
      swap(best, aux);
    }
  }
  if (best.empty()) {
    return {-1};
  }
  return best;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  debug(solution(5,	{2,1,1,1,0,0,0,0,0,0,0}));
  debug(solution(1,	{1,0,0,0,0,0,0,0,0,0,0}));
  debug(solution(9,	{0,0,1,2,0,1,1,1,1,1,1}));
  debug(solution(10,	{0,0,0,0,0,0,0,0,3,4,3}));
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