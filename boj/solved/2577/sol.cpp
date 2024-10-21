#include <iostream>
#include <memory>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y, z;
  cin >> x >> y >> z;
  int w = x * y * z;
  unique_ptr<int[]> a(new int[10]);
  while (w > 0) {
    ++a[w % 10];
    w /= 10;
  }
  for (int i = 0; i < 10; i++) {
    cout << a[i] << '\n';
  }
  return 0;
}