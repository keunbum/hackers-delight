/**
 *    author:   keunbum
 *    created:  05.12.2020 18:02:12
 *    platform: goormide       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    int maxa = *max_element(a.begin(), a.end());
    int maxb = *max_element(b.begin(), b.end());
    cout << "SB"[maxa < maxb] << '\n';
  }
  return 0;
}