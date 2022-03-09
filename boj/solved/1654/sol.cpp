#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> k >> n;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  int low = 1;
  int high = (int) ((1LL << 31) - 1);
  while (low < high) {
    int mid = low + (high - low + 1) / 2;
    long long cnt = 0;
    for (int i = 0; i < k; i++) {
      cnt += a[i] / mid;
    }
    if (cnt < n) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  cout << low << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
  * 0-based or 1-based?
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/