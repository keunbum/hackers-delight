#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

class dsu {
public:
  int n;
  vector<int> p;

  dsu(int _n) : n(_n), p(n) {
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = (int) 1e4;
  cout << N << '\n';
  vector<pair<int, int>> edges;
  dsu d(N);
  while ((int) edges.size() < N - 1) {
    int x, y;
    while (true) {
      x = rng() % N;
      y = rng() % N;
      if (x != y && d.unite(x, y)) {
        break;
      }
    }
    edges.emplace_back(x, y);
  }
  for (int i = 0; i < N - 1; i++) {
    cout << edges[i].first + 1 << " " << edges[i].second + 1 << '\n';
  }
  return 0;
}