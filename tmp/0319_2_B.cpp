#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int MAX_TIME = (int) (1e5 + 1e3);

vector<string> solution(vector<string> arr, vector<string> processes) {
  int n = (int) processes.size();
  vector<tuple<int, int, int, int, int, string>> ps(n);
  map<int, int> mp;
  for (int id = 0; id < n; id++) {
    istringstream sin(processes[id]);
    string cmd;
    int type, t1, t2, A, B;
    string C = " ";
    sin >> cmd >> t1 >> t2 >> A >> B;
    if (cmd == "read") {
      type = 1;
    }
    if (cmd == "write") {
      type = 0;
      sin >> C;
    }
    mp[t1] = id;
    ps[id] = make_tuple(type, t1, t2, A, B, C);
//    debug(id, ps[id]);
  }
  int total_time = 0;
  vector<string> ret;
  vector<int> cnts(MAX_TIME, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s; // <type, id>
  for (int t = 1; t < MAX_TIME; total_time += (cnts[t] >= 1), t++) {
//    debug(t);
    auto it = mp.find(t);
    if (it != mp.end()) {
      int id = it->second;
      int type = get<0>(ps[id]);
      s.emplace(type, id);
//      debug(id, type);
    } else {
      if (s.empty()) {
        continue;
      }
    }
//    assert(!s.empty());
//    debug(cnts[t]);
    while (!s.empty()) {
      if (cnts[t] == 2) {
        break;
      }
      if (cnts[t] == 1) {
          auto[type, id] = s.top();
          if (type == 0) {
            break;
          }
          s.pop();
          int t2 = get<2>(ps[id]);
          int A = get<3>(ps[id]);
          int B = get<4>(ps[id]);
          string cs;
          for (int T = A; T <= B; T++) {
            cs += arr[T];
          }
          for (int i = 0; i < t2; i++) {
            cnts[i + t] |= 1;
          }
          ret.push_back(cs);
//          debug(id, type, A, B);
      }
      if (cnts[t] == 0) {
        auto[type, id] = s.top();
        s.pop();   
        int t2 = get<2>(ps[id]);
        int A = get<3>(ps[id]);
        int B = get<4>(ps[id]);
        if (type == 0) {
          string C = get<5>(ps[id]);
          for (int T = A; T <= B; T++) {
            arr[T] = C;
          }
          for (int i = 0; i < t2; i++) {
            cnts[i + t] |= 2;
          }
//          debug(id, type, A, B, C);
        }
        if (type == 1) {
          string cs;
          for (int T = A; T <= B; T++) {
            cs += arr[T];
          }
          for (int i = 0; i < t2; i++) {
            cnts[i + t] |= 1;
          }
          ret.push_back(cs);
//          debug(id, type, A, B);
        }
      }
    }
  }
  /*
  cerr << "cnts: ";
  for (int t = 0; t <= 14; t++) {
    cerr << cnts[t] << " ";
  }
  cerr << endl;
  */
  ret.push_back(to_string(total_time));
  return ret;
}

int main() {
  vector<string> res;
//  res = solution({"1", "2", "4", "3", "3", "4", "1", "5"}, {"read 1 3 1 2", "read 2 6 4 7", "write 4 3 3 5 2", "read 5 2 2 5", "write 6 1 3 3 9", "read 9 1 0 7"});
//  debug(res);
  res = solution({"1", "1", "1", "1", "1", "1", "1"}, {"write 1 12 1 5 8", "read 2 3 0 2", "read 5 5 1 2", "read 7 5 2 5", "write 13 4 0 1 3", "write 19 3 3 5 5", "read 30 4 0 6", "read 32 3 1 5"});
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