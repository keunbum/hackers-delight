class Solution {
public:
  int romanToInt(string s) {
    init();
    map<string, int> mp;
    for (int x = 1; x < 4000; x++) {
      string t = "";
      mp[t] = x;
    }
    cout << mp[s] << '\n';      
  }
};
/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to their limitations
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. keep calm
  
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
*/