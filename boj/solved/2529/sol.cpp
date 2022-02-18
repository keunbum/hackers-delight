#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int digit = 10;
  vector<int> P(digit);
  int e = 1;
  for (int i = 0; i < digit; i++) {
    P[i] = e;
    e *= 10;
  }
  int k;
  cin >> k;
  vector<bool> f(k);
  for (int i = 0; i < k; i++) {
    char ch;
    cin >> ch;
    f[i] = (ch == '<');
  }
  long long mn = 9876543210;
  long long mx = 0;
  for (int bs = 1; bs < (1 << digit); bs++) {
    vector<int> p;
    for (int i = 0; i < digit; i++) {
      if ((bs >> i) & 1) {
        p.push_back(i);
      }
    }
    if ((int) p.size() != k + 1) {
      continue;
    }
    do {
      bool ok = true;
      for (int i = 0; i < k; i++) {
        if (f[i] ^ (p[i] < p[i + 1])) {
          ok = false;
          break;
        }
      }
      if (ok) {
        long long x = 0;
        for (int i = 0; i < k + 1; i++) {
          x = x * 10 + p[i];
        }
        mn = min(mn, x);
        mx = max(mx, x);
      }
    } while (next_permutation(p.begin(), p.end()));
  }
  auto Inv = [&](long long x) {
    string ret;
    for (int i = k; i >= 0; i--) {
      ret += (char) (x / P[i] % 10 + '0');
    }
    return ret;
  };
  cout << Inv(mx) << '\n' << Inv(mn) << '\n';
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