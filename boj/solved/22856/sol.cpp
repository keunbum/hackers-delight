#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 2>> tree(n + 1);
  for (int _ = 0; _ < n; ++_) {
    int x;
    cin >> x >> tree[x][0] >> tree[x][1];
  }
  int e = 0;
  vector<int> dist(n + 1);
  function<void(int)> DFS = [&](int v) {
    for (int i = 0; i < 3; ++i) {
      if (i == 1) {
        e = v;
      } else {
        int u = tree[v]["021"[i] - '0'];
        if (u != -1) {
          dist[u] = dist[v] + 1;
          DFS(u);
        }
      }
    }
  };
  dist[1] = 0;
  DFS(1);
  cout << (2 * (n - 1) - dist[e]) << '\n';
  return 0;
}
