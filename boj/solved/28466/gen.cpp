#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  assert(argc == 2);
  int N = atoi(argv[1]);
  cout << N << '\n';
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cout << 0 << " \n"[j == 10 - 1];
    }
  }
  for (int i = 0; i < 12; ++i) {
    for (int j = 0; j < 12; ++j) {
      cout << 0 << " \n"[j == 12 - 1];
    }
  }
  vector<string> SS;
  {
    int x = 0;
    int y = 0;
    for (int i = 0; i < 60; ++i) {
      SS.push_back({(char) (x + '0'), (char) (y + 'A')});
      x = (x + 1) % 10;
      y = (y + 1) % 12;
    }
  }
  for (int i = 0; i < N; ++i) {
    int X = rng() % 5 + 1;
    string S = SS[rng() % SS.size()];
    cout << X << ' ' << S << '\n';
  }
  return 0;
}