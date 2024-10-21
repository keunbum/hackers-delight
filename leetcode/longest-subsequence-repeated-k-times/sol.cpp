#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

class Solution {
private:
    bool IsSubK(const string& s, const string& t, int k) {
        int at = 0;
        for (char ch : s) {
            if (ch == t[at]) {
                at = (at + 1) % int(t.size());
                if (at == 0 && --k == 0) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> cnt(26, 0);
        for (char ch : s) {
            cnt[int(ch - 'a')] += 1;
        }
        vector<string> que{""};
        for (int b = 0; b < int(que.size()); ++b) {
            string cur = que[b];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                cur.push_back(ch);
                if (IsSubK(s, cur, k)) {
                  que.push_back(cur);
                }
                cur.pop_back();
            }
        }
        return que.back();
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution solver;
  string s;
  int k;
  while (cin >> s >> k) {
    cout << solver.longestSubsequenceRepeatedK(s, k) << '\n';
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * Do I have to solve like this?
  
 * stuff you should look for
  * 0-based or 1-based?
  * off-by-one error
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/