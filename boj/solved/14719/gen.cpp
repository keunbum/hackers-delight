#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h = 500;
  int w = 500;
  cout << h << " " << w << '\n';
  for (int j = 0; j < w; j++) {
    if (j > 0) {
      cout << " ";
    }
    if (j == 0 || j == w - 1) {
      cout << 500;
    } else {
      cout << 0;
    }
  }
  return 0;
}