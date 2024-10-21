#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

double fRand(double fMin, double fMax) {
  double f = (double) rng() / RAND_MAX;
  return fMin + f * (fMax - fMin);
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const long long MAX = 3e9;
  double x = fRand(0, MAX);
  double y = fRand(0, MAX / 1e1);
  double c = fRand(y / 1e2, y / 1e1);
  cout << fixed << setprecision(6) << x << " " << y << " " << c << '\n';
  return 0;
}