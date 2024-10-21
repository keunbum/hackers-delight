#include <iostream>
#include <queue>

using namespace std;

queue<int> que;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "push") {
      cin >> t;
      que.push(t);
    } else {
      char c = s[0];
      int size = que.size();
      switch (c) {
        case 'p':
          if (size > 0) {
            cout << que.front();
            que.pop();
          } else {
            cout << -1;
          }
          break;
        case 's':
          cout << size;
          break;
        case 'e':
          cout << que.empty();
          break;
        case 'f':
          if (size > 0) {
            cout << que.front();
          } else {
            cout << -1;
          }
          break;
        case 'b':
          if (size > 0) {
            cout << que.back();
          } else {
            cout << -1;
          }
          break;
        default:
          break;
      }
      cout << '\n';
    }
  }
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}