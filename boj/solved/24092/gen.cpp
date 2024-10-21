#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = (int) 1e4 + 0;
  vector<int> a(N);
  iota(a.begin(), a.end(), 1);
  auto b = a;
  cout << N << '\n';
  {
    shuffle(a.begin(), a.end(), rng);
    /*
    int b = 0;
    int e = N - 1;
    int cnt = N;
    while (b < e) {
        a[b++] = cnt--;
        a[e--] = cnt--;
    }
    if (b == e) {
      a[b] = cnt--;
    }
    assert(cnt == 0);
    */
    for (int i = 0; i < N; i++) {
      cout << a[i] << " \n"[i == N - 1];
    }
  }
  {
//    reverse(b.begin(), b.end());
//    shuffle(b.begin(), b.end(), rng);
    for (int i = 0; i < N; i++) {
      cout << b[i] << " \n"[i == N - 1];
    }
  }
  return 0;
}