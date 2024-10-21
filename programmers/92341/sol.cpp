#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

int Encode(string hhmm) {
  return 60 * stoi(hhmm.substr(0, 2)) + stoi(hhmm.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
  const int END = Encode("23:59");
  map<string, int> total_times;
  map<string, int> time_of_entry;
  for (const string& record : records) {
    istringstream sin(record);
    string hhmm, id, type;
    sin >> hhmm >> id >> type;
    int cur_time = Encode(hhmm);
    debug(hhmm, id, type, cur_time);
    if (type == "IN") {
      time_of_entry[id] = cur_time;
    }
    if (type == "OUT") {
      total_times[id] += cur_time - time_of_entry[id];
      time_of_entry[id] = -1;
    }
  }
  for (auto&[id, time] : time_of_entry) {
    if (time != -1) {
      total_times[id] += END - time;
    }
    debug(id, time, total_times[id]);
  }
  vector<int> ret;
  for (auto&[id, time] : total_times) {
    int over = max(time - fees[0], 0);
    int cost = fees[1] + (over + fees[2] - 1) / fees[2] * fees[3];
    debug(over, cost);
    ret.push_back(cost);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solution({}, {"05:34 5961 IN"});
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * deep breathing. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH(feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/