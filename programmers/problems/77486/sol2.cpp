#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> solution1(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
  map<string, int> mp;
  int n = (int) enroll.size();
  mp["-"] = n;
  vector<int> p(n + 1, -1);
  vector<int> deg(n + 1, 0);
  for (int i = 0; i < n; i++) {
    mp[enroll[i]] = i;
    int j = mp[referral[i]];
    p[i] = j;
    deg[j] += 1;
  }
//  debug(p, deg);
  vector<int> me(n + 1, 0);
  vector<int> give(n + 1, 0);
  for (int i = 0; i < (int) seller.size(); i++) {
    int id = mp[seller[i]];
    int m = amount[i] * 100;
    me[id] += m;
    give[id] += m / 10;
  }
//  debug(me, give);
  vector<int> que;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) {
      que.push_back(i);
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    int v = que[b];
    int pv = p[v];
    me[v] -= give[v];
    me[pv] += give[v];
    give[pv] += give[v] / 10;
    if (--deg[pv] == 0 && pv != n) {
      que.push_back(pv);
    }
//    debug(v, enroll[v], me);
  }
  debug(me);
  assert(accumulate(me.begin(), me.end(), 0) / 100 == accumulate(amount.begin(), amount.end(), 0));
  me.resize(n);
  return me;
}


vector<int> solution2(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
  map<string, int> mp;
  int n = (int) enroll.size();
  mp["-"] = n;
  vector<int> p(n + 1, -1);
  vector<int> deg(n + 1, 0);
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

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    int n = 5;
    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n + 1; j++) {
        edges.emplace_back(i, j);
      }
    }
    vector<int> b;
    vector<int> deg;
    while (true) {
      vector<int>(n + 1, 0).swap(deg);
      vector<int>(n + 1, -1).swap(b);
      shuffle(edges.begin(), edges.end(), rng);
      vector<int> p(n + 1);
      iota(p.begin(), p.end(), 0);
      function<int(int)> Get = [&](int v) {
        return v == p[v] ? v : p[v] = Get(p[v]);
      };
      int edge_cnt = 0;
      for (auto&[i, j] : edges) {
        if (edge_cnt == n + 1 - 1) {
          break;
        }
        int I = Get(i);
        int J = Get(j);
        if (I != J) {
          p[I] = J;
          b[i] = j;
          deg[j] += 1;
          edge_cnt += 1;
        }
      }
      int cnt = 0;
      for (int i = 0; i < n + 1; i++) {
        cnt += (b[i] == -1);
      }
      if (cnt == 1 && b[n] == -1) {
        break;
      }
    }
    debug(b, deg);
    int m = 5;
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
      c[i] = rng() % m;
    }
    int mm = 3;
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
      d[i] = rng() % mm + 1;
    }
    vector<int> order(n + 1);
    {
      vector<int> que;
      for (int i = 0; i < n + 1; i++) {
        if (deg[i] == 0) {
          que.push_back(i);
        }
      }
      for (int ptr = 0; ptr < (int) que.size(); ptr++) {
        int v = que[ptr];
        debug(v);
        order[v] = ptr;
        int pr = b[v];
        if (pr != -1 && --deg[pr] == 0) {
          que.push_back(pr);
        }
      }
    }
    debug(order);
    sort(a.begin(), a.end(), [&](int i, int j) {
      return order[i] > order[j];
    });
    debug(a);
    a.erase(a.begin());
    auto GetS = [&](vector<int>& v) {
      vector<string> ret(v.size());
      for (int i = 0; i < (int) v.size(); i++) {
        if (v[i] != -1) {
          ret[i] = v[i] == n ? "-" : string(1, (char) ('a' + v[i]));
        }
      }
      return ret;
    };
    auto A = GetS(a);
    vector<string> B(n);
    for (int i = 0; i < n; i++) {
      B[i] = b[a[i]] == n ? "-" : string(1, (char) ('a' + b[a[i]]));
    }
    auto C = GetS(c);
    auto D = d;
    debug(A, B, C, D);
    if (solution1(A, B, C, D) != solution2(A, B, C, D)) {
      break;
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