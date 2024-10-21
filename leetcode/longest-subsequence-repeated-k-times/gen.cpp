#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int, char *[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    s += ch;
    string a = s;
  //  iota(a.begin(), a.end(), 'a');
    while (a.size() < 2000) {
      a += a;
    }
    int k = int(a.size()) / 8 + 1;
    cout << a << " " << k << '\n';
  }
  return 0;
}