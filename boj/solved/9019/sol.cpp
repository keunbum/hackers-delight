#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e4;

inline int D(int x) { return (x + x) % md; }

inline int S(int x) { return (x + 9999) % md; }

inline int L(int x) {
  int d1 = x / 1000;
  int d2 = (x / 100) % 10;
  int d3 = (x / 10) % 10;
  int d4 = x % 10;
  return ((d2 * 10 + d3) * 10 + d4) * 10 + d1; 
}

inline int R(int x) {
  int d1 = x / 1000;
  int d2 = (x / 100) % 10;
  int d3 = (x / 10) % 10;
  int d4 = x % 10;
  return ((d4 * 10 + d1) * 10 + d2) * 10 + d3; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int st, en;
    cin >> st >> en;
    vector<int> dist(md, -1);
    dist[st] = 0;
    vector<int> que(1, st);
    vector<int> pre(md, -1);
    for (int b = 0; b < (int) que.size(); b++) {
      int v = que[b];
      for (auto GetU : {D, S, L, R}) {
        int u = GetU(v);
        if (dist[u] == -1) {
          dist[u] = dist[v] + 1;
          pre[u] = v;
          que.push_back(u);
        }
      }
    }
    string cmds;
    int v = en;
    while (pre[v] != -1) {
      int u = pre[v];
      if (v == D(u)) cmds += 'D'; else
      if (v == S(u)) cmds += 'S'; else
      if (v == L(u)) cmds += 'L'; else
      if (v == R(u)) cmds += 'R';
      v = u;
    }
    reverse(cmds.begin(), cmds.end());
    cout << cmds << '\n';
  }
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