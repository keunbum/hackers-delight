#include <iostream>
#include <vector>

using namespace std;

const int MAX = 129;

int cnt[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int size = s.length();
  for (int i = 0; i < size; i++) {
    char t = s[i];
    if (t >= 'a')
      t += 'A' - 'a';
    cnt[(int)t]++;
  }
  vector<int> mm(1, 0);
  for (int i = 1; i < MAX; i++) {
    if (cnt[mm[0]] < cnt[i]) {
      mm.clear();
      mm.push_back(i);
    }
    else if (cnt[mm[0]] == cnt[i]) {
      mm.push_back(i);
    }
  }
  cout << (mm.size() == 1 ? (char) (mm[0]) : '?') << '\n';
//cerr << (float)clock()/CLOCKS_PER_SEC << " seconds." << '\n';
  return 0;
}