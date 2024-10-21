#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int HM2M(string s) {        
  return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

const array<int, 7> TO_I = {9, 11, 0, 2, 4, 5, 7};

string Encode(string& s) {
  s += ' ';
  string ret;
  string cur = "";
  int n = (int) s.size();
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      assert(1 <= cur.size() && cur.size() <= 2);
      ret.push_back((char) (TO_I[(int) (cur[0] - 'A')] + (int) (cur.size() == 2)));
      cur = "";
    }
    cur += s[i];
    if (i + 1 < n && s[i + 1] == '#') {
      cur += s[i + 1];
      i += 1;
    }
  }
  return ret;
}

string solution(string m, vector<string> musicinfos) {
  debug(m, musicinfos);
  auto me = Encode(m);
  debug(me);
  int best_play_time = -1;
  string best_title;
  for (auto& info : musicinfos) {
    vector<string> strs;
    info += ',';
    string cur;
    for (char ch : info) {
      if (ch == ',') {
        strs.push_back(cur);
        cur = "";
      } else {
        cur += ch;
      }
    }
    debug(strs);
//    int play_time = HM2M(strs[1] == "00:00" ? "24:00" : strs[1]) - HM2M(strs[0]);
    int play_time = HM2M(strs[1]) - HM2M(strs[0]);
    if (play_time < (int) me.size()) {
      continue;
    }
    debug(play_time);
    auto him = Encode(strs[3]);
    string notes;
    for (int i = 0; i < play_time / (int) him.size(); i++) {
      notes += him;
    }
    for (int i = 0; i < play_time % (int) him.size(); i++) {
      notes += him[i];
    }
    debug(notes);
    assert(notes.size() >= me.size());
    if (notes.find(me) != string::npos && play_time > best_play_time) {
      best_play_time = play_time;
      best_title = strs[2];
    }
  }
  debug(best_title);
  if (best_title == "") {
    return "(None)";
  }
  return best_title;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution("ABCDEFG", {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"});
  solution("CC#BCC#BCC#BCC#B", {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"});
  solution("ABC", {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"}); 
  solution("A", {"00:00,00:04,HH,BCDA"});
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