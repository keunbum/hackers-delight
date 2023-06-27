#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int A = 0, B = 0, C = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    A += a[i] == 1;
    B += a[i] == 2;
    C += a[i] == 3;
  }
  int U, D;
  cin >> U >> D;
  U -= min(U, A);
  D -= min(D, B);
  if (C < U + D) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
    string s;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1) s += 'U'; else
      if (a[i] == 2) s += 'D'; else
      if (U-- > 0) {
        s += 'U';
      } else {
        s += 'D';
      }
    }
    cout << s << '\n';
  }
  return 0;
}
