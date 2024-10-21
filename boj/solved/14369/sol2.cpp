#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef TMP
  const vector<string> SS{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
  {
    vector<int> cnt(26, 0);
    for (int i = 0; i < 10; i++) {
      for (char ch : SS[i]) {
        cnt[(int)(ch-'A')] += 1;
      }
    }
    vector<vector<pair<int, int>>> res(26);
    for (int i = 0; i < 26; i++) {
      char ch = (char) (i + 'A');
      for (int j = 0; j < 10; j++) {
        int t = count(SS[j].begin(), SS[j].end(), ch);
        if (t > 0) {
          res[i].emplace_back(j, t);
        }
      }
    }
    vector<int> order(26);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return res[i].size() < res[j].size();
    });
    for (int id : order) {
      int sz = (int) res[id].size();
      if (sz == 0) {
        continue;
      }
      cout << ((char) (id + 'A')) << ": " << sz << " --> ";
      for (int i = 0; i < sz; i++) {
        if (i > 0) {
          cout << ", ";
        }
        auto[num, alpha_cnt] = res[id][i];
        cout << num << "(" << SS[num] << "): " << alpha_cnt;
      }
      cout << '\n';
    }
  }
#endif
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    string s;
    cin >> s;
    vector<int> cnt(128, 0);
    for (char ch : s) {
      cnt[(int) ch] += 1;
    }
    vector<int> res(10, 0);
    res[0] = cnt['Z'];
    res[6] = cnt['X'];
    res[2] = cnt['W'];
    res[4] = cnt['U'];
    res[8] = cnt['G'];
    res[7] = cnt['S'] - res[6];
    res[5] = cnt['V'] - res[7];
    res[3] = cnt['H'] - res[8];
    res[1] = cnt['O'] - (res[0] + res[2] + res[4]);
    res[9] = cnt['I'] - (res[5] + res[6] + res[8]);
    string ans;
    for (int i = 0; i < 10; i++) {
      assert(res[i] >= 0);
      ans += string(res[i], (char) (i + '0'));
    }
    assert(!ans.empty());
    cout << ans << '\n';
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/