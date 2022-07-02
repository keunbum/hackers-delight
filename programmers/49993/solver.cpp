#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int Encode(char ch) { return (int) (ch - 'A'); }

int solution(string skill, vector<string> skill_trees) {
  const int alpha = 26;
  vector<int> pos(alpha, -1);
  for (int i = 0; i < (int) skill.size(); i++) {
    pos[Encode(skill[i])] = i;
  }
  int ret = 0;
  for (string& str : skill_trees) {      
    int pre = -1;
    bool ok = true;
    for (char ch : str) {
      if (pos[Encode(ch)] == -1) {
        continue;
      }
      if (pre + 1 != pos[Encode(ch)]) {
        ok = false;
        break;
      }
      pre = pos[Encode(ch)]; 
    }
    debug(str, ok);
    ret += ok;
  }
  return ret;
}

int main() {
  solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"});
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