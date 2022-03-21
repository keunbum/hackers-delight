#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int Encode(char ch) {
  return (int) (ch - 'a');
}

char Decode(int i) {
  return (char) ('a' + i);
}

const int alpha = 26;

struct node {
  vector<node*> nodes;
  set<int> ids;

  node() : nodes(alpha, nullptr) {}

  void add(int id, int i, const string& s) {
    if (i >= (int) s.size()) {
      return;
    }
    if (nodes[Encode(s[i])] == nullptr) {
      nodes[Encode(s[i])] = new node();
    }
    nodes[Encode(s[i])]->ids.insert(id);
    nodes[Encode(s[i])]->add(id, i + 1, s);
  }
};

vector<string> solution(vector<string> goods) {
  debug("HI0");
  int n = (int) goods.size();
  node* root = new node();
  for (int id = 0; id < n; id++) {
    for (int i = 0; i < (int) goods[id].size(); i++) {
      root->add(id, 0, goods[id].substr(i));
    }
  }
  for (int nid = 0; nid < alpha; nid++) {
    if (root->nodes[nid] != nullptr) {
      debug(nid, Decode(nid));
    }
  }
  debug("HI1");
  vector<pair<node*, string>> que(1, make_pair(root, ""));
  vector<int> used(n, 21);
  vector<vector<string>> ss(n);
  int depth = 0;
  while (!que.empty()) {
    debug(depth);
    debug(que.size());
    vector<pair<node*, string>> new_que;
    map<int, vector<string>> mp;
    for (int b = 0; b < (int) que.size(); b++) {
      auto[v, ac] = que[b];
      for (int nid = 0; nid < alpha; nid++) {
        node* u = v->nodes[nid];
        if (u == nullptr) {
          continue;
        }
        string nac = ac + Decode(nid);
        if (u->ids.size() == 1) {
          int id = *u->ids.begin();
          if (used[id] >= (int) nac.size()) {
            used[id] = nac.size();
            mp[id].push_back(nac);
          }
        }
        new_que.push_back(make_pair(u, nac));
      }
    }
    debug(used);
    for (auto[id, strs] : mp) {
      debug(id, strs); 
      ss[id] = strs;
    }
    swap(que, new_que);
    depth += 1;
  }
  debug("HI2");
  debug(ss);
  vector<string> ret(n);
  for (int id = 0; id < n; id++) {
    sort(ss[id].begin(), ss[id].end());
    for (const string& str : ss[id]) {
      if (ret[id] != "") {
        ret[id] += " ";
      }
      ret[id] += str;
    }
    if (ret[id] == "") {
      ret[id] = "None";
    }
  }
  debug("HI3");
  return ret;
}

int main() {
//  auto res = solution({"pencil", "cilicon", "contrabase", "picturelist"});
//  debug(res);
    auto res = solution({"abcdeabcd", "cdabe", "abce", "bcdeab"});
    debug(res);
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