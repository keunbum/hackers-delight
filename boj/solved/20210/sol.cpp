#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

array<int, 128> prio;

inline bool IsDigit(char ch) { return (int) (ch - '0') < 10; }

int AlphaCmp(const string& si, const string& sj) {
  int N = (int) si.size();
  int M = (int) sj.size();
  for (int i = 0; i < min(N, M); i++) {
    if (prio[si[i]] != prio[sj[i]]) {
      return prio[si[i]] - prio[sj[i]];
    }
  }
  return N - M;
}

int DigitCmp(const string& si, const string& sj) {
  int N = (int) si.size();
  int M = (int) sj.size();
  int i = 0;
  int j = 0;
  while (i < N && si[i] == '0') {
    ++i;
  }
  while (j < M && sj[j] == '0') {
    ++j;
  }
  auto Cmp = [&](int i, int j) -> int {
    if (N - i == M - j) {
      while (i < N && j < M) {
        if (si[i] != sj[j]) {
          return si[i] - sj[j];
        }
        ++i;
        ++j;
      }
      return 0;
    }
    return (N - i) - (M - j);
  };
  int z = Cmp(i, j);
  if (z == 0) {
    return i - j;
  }
  return z;
}

string GetPiece(const string& s, int N, int i) {
  char ch = s[i];
  i++;
  string ret(1, ch);
  while (i < N && (IsDigit(ch) == IsDigit(s[i]))) {
    ret += s[i];
    ++i;
  }         
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 26; i++) {
    prio[i + 'A'] = 'A' + i + i;
    prio[i + 'a'] = 'A' + i + i + 1;
  } 
  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; i++) {
    cin >> strs[i];
  }
  sort(strs.begin(), strs.end(), [&](const string& si, const string& sj) {
    int i = 0;
    int j = 0;
    int N = (int) si.size();
    int M = (int) sj.size();
    while (i < N && j < M) {
      string pi = GetPiece(si, N, i);
      i += (int) pi.size();
      string pj = GetPiece(sj, M, j);
      j += (int) pj.size();
      if (IsDigit(pi[0]) ^ IsDigit(pj[0])) {
        return pi[0] < pj[0];
      }
      if (!IsDigit(pi[0]) && !IsDigit(pj[0])) {
        int z = AlphaCmp(pi, pj);
        if (z != 0) {
          return z < 0;
        }
        continue;
      }
      int z = DigitCmp(pi, pj);
      if (z != 0) {
        return z < 0;
      }
    }
    return N < M;
  });
  for (int i = 0; i < n; i++) {
    cout << strs[i] << '\n';
  }
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