#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int f, st, en, up, dn;
  cin >> f >> st >> en >> up >> dn;
  --st; --en;
  dn *= -1;
  vector<int> dist(f, -1);
  dist[st] = 0;
  vector<int> que(1, st);
  for (int b = 0; b < (int) que.size(); b++) {
    int v = que[b];
    if (v == en) {
      cout << dist[v] << '\n';
      return 0;
    }
    for (int d : {up, dn}) {
      int u = v + d;
      if (u < 0 || u >= f || dist[u] != -1) {
        continue;
      }
      dist[u] = dist[v] + 1;
      que.push_back(u);
    }
  }
  cout << "use the stairs" << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
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