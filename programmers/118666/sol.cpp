#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

string solution(vector<string> survey, vector<int> choices) {
  const int A[] = {3, 2, 1, 0};
  const int B[] = {1, 2, 3};
  array<int, 128> cnts{};
  for (int i = 0; i < (int) survey.size(); i++) {
    string s = survey[i];
    int v = choices[i];
    if (v < 5) {
      cnts[s[0]] += A[v - 1];
    } else {
      cnts[s[1]] += B[v - 5];
    }
  }
  string ret;
  for (string xy : {"RT", "CF", "JM", "AN"}) {
    ret += (cnts[xy[0]] >= cnts[xy[1]] ? xy[0] : xy[1]);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({"AN", "CF", "MJ", "RT", "NA"},	{5, 3, 2, 7, 5});
  solution({"TR", "RT", "TR"},	{7, 1, 3});
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * keep calm
  
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