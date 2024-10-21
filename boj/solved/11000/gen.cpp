#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n = atoi(argv[1]);
  int X = atoi(argv[2]);
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    int x, y;
    do {
      x = rng() % X;
      y = rng() % X; 
    } while (x >= y);
    cout << x << " " << y << endl;
  }
  return 0;
}