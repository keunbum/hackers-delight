#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<string> solution(vector<string> files) {
  auto Get = [](const string& s) {
    string ret1;
    int i = 0;
    while (s[i] < '0' || s[i] > '9') {
      ret1 += (s[i] | 32);
      i += 1;
    }
    int ret2 = 0;
    while (i < (int) s.size() && '0' <= s[i] && s[i] <= '9') {
      ret2 = ret2 * 10 + (int) (s[i] - '0');
      i += 1;
    }
    debug(s, ret1, ret2);
    return make_pair(ret1, ret2);
  };
  stable_sort(files.begin(), files.end(), [&](auto& si, auto& sj) {
    return Get(si) < Get(sj);
  });
  debug(files);
  return files;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"});
  solution({"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"});
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