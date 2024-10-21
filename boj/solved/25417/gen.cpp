#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  array<int, 25> a;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int k = rng () % 3;
      int A[] = {-1, 0, 7};
      a[i * 5 + j] = A[k];
    }
  }
  a[0] = 1;
  shuffle(a.begin(), a.end(), rng);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << a[i * 5 + j] << " \n"[j == 4];
    }
  }
  int r, c;
  do {
    r = rng() % 5;
    c = rng() % 5;
  } while (a[r * 5 + c] != 0);
  cout << r << " " << c;
  return 0;
}