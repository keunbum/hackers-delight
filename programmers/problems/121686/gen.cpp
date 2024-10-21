#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = (int) 1e4;
  vector<tuple<int, int, int>> res;
  set<pair<int, int>> s;
  while ((int) s.size() < N) {
    int a = rng() % 10 + 1;
    //int b = rng() % ((int) 1e7 + 1);
    //int c = rng() % 1000 + 1;
    int b = rng() % ((int) 2e3);
    int c = rng() % 500;
    if (s.emplace(a, b).second) {
      res.emplace_back(a, b, c);
    }
  }
  cout << N << '\n';
  for (auto&[x, y, z] : res) {
    cout << x << " " << y << " " << z << '\n';
  }
  return 0;
}