#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> p, int k) {
  vector<int> que;
  int n = (int) p.size();
  for (int id = 0; id < n; id++) {
    que.push_back(id);
  }
  vector<int> idx(n, -1);
  int cnt = 0;
  for (int b = 0; b < (int) que.size(); b++) {
    int id = que[b];
    if (p[id] < *max_element(p.begin(), p.end())) {
      que.push_back(id);
    } else {
      idx[id] = cnt++;
      p[id] = 0;
    }
  }
  assert(cnt == n);
  return idx[k] + 1;
}