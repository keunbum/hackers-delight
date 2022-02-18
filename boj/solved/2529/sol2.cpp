#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
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
  vector<bool> was(10, false);
  function<void(int, long long)> Dfs = [&](int v, long long cur) {
    if (v == k + 1) {
      mn = min(mn, cur);
      mx = max(mx, cur);
      return;
    }
    if (v == 0 || f[v - 1]) {
      for (int i = (v == 0 ? -1 : cur % 10) + 1; i < 10; i++) {
        if (!was[i]) {
          was[i] = true;
          Dfs(v + 1, cur * 10 + i);
          was[i] = false;
        }
      }      
    } else {
      for (int i = cur % 10 - 1; i >= 0; i--) {
        if (!was[i]) {
          was[i] = true;
          Dfs(v + 1, cur * 10 + i);
          was[i] = false;
        }
      }
    } 
  };
  Dfs(0, 0);
  auto Decode = [&](long long x) {
    string ret;
    for (int i = 0; i < k + 1; i++) {
      ret += (char) (x % 10 + '0');
      x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  };
  cout << Decode(mx) << '\n' << Decode(mn) << '\n';
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