#include <bits/stdc++.h>

using namespace std;

map<string, int> BIT = {
  {"cpp", 0}, {"java", 1}, {"python", 2},
  {"backend", 0}, {"frontend", 1},
  {"junior", 0}, {"senior", 1},
  {"chicken", 0}, {"pizza", 1},
  
  {"-", -1}
};

const int F[4] = {2, 1, 1, 1};
const int SHIFT[4] = {3, 2, 1, 0};

vector<int> solution(vector<string> info, vector<string> query) {
  vector<pair<int, int>> a(info.size());
  vector<int> cnt(1 << 5, 0);
  for (int i = 0; i < (int) info.size(); i++) {
    istringstream sin(info[i]);
    vector<string> argv(4);
    sin >> argv[0] >> argv[1] >> argv[2] >> argv[3] >> a[i].first;
    for (int id = 0; id < 4; id++) {
      a[i].second |= (BIT[argv[id]] << SHIFT[id]);
    }
    cnt[a[i].second] += 1;
  }
  sort(a.begin(), a.end());
  vector<tuple<int, int, vector<int>>> b(query.size(), {-1, 0, vector<int>(4)});
  for (int i = 0; i < (int) query.size(); i++) {
    istringstream sin(query[i]);
    get<0>(b[i]) = i; 
    for (int id = 0; id < 4; id++) {
      string s, t;
      sin >> s >> t;
      get<2>(b[i])[id] = BIT[s];
      if (id == 3) {
        get<1>(b[i]) = stoi(t);
      }
    }
  }
  sort(b.begin(), b.end(), [](const tuple<int, int, vector<int>>& ti, const tuple<int, int, vector<int>>& tj) {
    return get<1>(ti) < get<1>(tj);
  });
  int ptr = 0;
  vector<int> ret(b.size());
  for (int i = 0; i < (int) b.size(); i++) {
    auto&[qid, score, bits] = b[i];
    while (ptr < (int) a.size() && a[ptr].first < score) {
      cnt[a[ptr].second] -= 1;
      ptr += 1;
    }
    vector<int> bss(1, 0);
    for (int sid = 0; sid < 4; sid++) {
      vector<int> new_bss;
      for (int bs : bss) {
        for (int f = 0; f <= F[sid]; f++) {
          if (bits[sid] == -1 || bits[sid] == f) {
            new_bss.push_back(bs | (f << SHIFT[sid]));
          }
        }
      }
      swap(bss, new_bss);
    }
    int cur = 0;
    for (int bs : bss) {
      cur += cnt[bs];
    }
    ret[qid] = cur;
  }
  return ret;
}

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