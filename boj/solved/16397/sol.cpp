#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e5;

const int P[5] = {1, 10, 100, 1000, 10000};

int A(int x) {
  return (++x == md) ? -1 : x;
}

int B(int x) {
  x += x;
  if (x >= md) return -1;
  for (int i = 4; i >= 0; i--) {
    if (x / P[i] % 10 != 0) return x - P[i];
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, T, G;
  cin >> N >> T >> G;
  vector<int> dist(md, -1);
  dist[N] = 0;
  vector<int> que(1, N);
  for (int b = 0; b < (int) que.size(); b++) {
    int v = que[b];
    for (int u : {A(v), B(v)}) {
      if (u == -1 || dist[u] >= 0) {
        continue;
      }
      dist[u] = dist[v] + 1;
      que.push_back(u);
    }
  }
  cout << (dist[G] == -1 || dist[G] > T ? "ANG" : to_string(dist[G])) << '\n';
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
  * performance or safety?
  * local or global?
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