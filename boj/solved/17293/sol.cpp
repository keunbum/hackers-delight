#include <bits/stdc++.h>

using namespace std;

string Decode(int x) {
  if (x == 0) return "no more bottles of beer";
  if (x == 1) return "1 bottle of beer";
  return to_string(x) + " bottles of beer";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int k = n; k >= 1; k--) {
    cout << Decode(k) << " on the wall, " << Decode(k) << "." << '\n';
    cout << "Take one down and pass it around, " << Decode(k - 1) << " on the wall." << '\n';
    cout << '\n';
  }
  cout << "No more bottles of beer on the wall, no more bottles of beer." << '\n';
  cout << "Go to the store and buy some more, " << Decode(n) << " on the wall." << '\n';
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