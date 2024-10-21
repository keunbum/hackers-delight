#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<long long> solution(vector<vector<int>> ps) {
  vector<long long> ret(11, 0);
  sort(ps.begin(), ps.end(), [](auto& pi, auto& pj) {
    return pi[1] < pj[1] || (pi[1] == pj[1] && pi[0] < pj[0]);
  });
//  debug(ps);
  auto Cmp = [&](int i, int j) {
    return ps[i][0] > ps[j][0] || (ps[i][0] == ps[j][0] && ps[i][1] > ps[j][1]);
  };
  priority_queue<int, vector<int>, decltype(Cmp)> s(Cmp);
  s.push(0);
  int i = 1;
  while (!s.empty()) {
    int j = s.top();
    s.pop();
//    debug(j, ret);
    if (ps[j][1] < ret[0]) {
      ret[ps[j][0]] += ret[0] - ps[j][1];
      ret[0] += ps[j][2];
    } else {
      ret[0] = ps[j][1] + ps[j][2];
    }
    while (i < (int) ps.size() && ps[i][1] < ret[0]) {
      s.push(i);
      i += 1;
    }
    if (s.empty() && i < (int) ps.size()) {
      s.push(i);
      i += 1;
    }
  }
//  debug(ret);
  return ret;
}

bool compare(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}
struct stru {
	int input;
	int times;
};
vector<long long> solution2(vector<vector<int>> program) {
	vector<long long> answer(11);

	for (int i = 0; i < program.size(); i++) {
		program[i].push_back(i + 1);
	}

	sort(program.begin(), program.end(), compare);

	long long t = 0;
	queue<stru> que[11];
	int index = 0;
	int check = 0;
	int tmp = 0;
	while (tmp != program.size()) {
		if (check == 0) {
			que[program[index][0]].push({ program[index][1], program[index][2] });
			t = max(t, (long long) program[index][1]);
			index++;
			check++;
		}
		while (index < program.size() && program[index][1] <= t) {
			que[program[index][0]].push({ program[index][1], program[index][2] });
			check++;
			index++;
		}
		for (int i = 1; i < 11; i++) {
			if (!que[i].empty()) {
				stru temp = que[i].front();
				que[i].pop();
				tmp++;
				answer[i] += t - temp.input;
				t += temp.times;
				check--;
				break;
			}
		}
	}
	answer[0] = t;
	return answer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  while (true) {
    int N = (int) 3e0;
    vector<vector<int>> res;
    set<pair<int, int>> s;
    while ((int) s.size() < N) {
      int a = rng() % 10 + 1;
      //int b = rng() % ((int) 1e7 + 1);
      //int c = rng() % 1000 + 1;
      int b = rng() % ((int) 2e1);
      int c = rng() % 20;
      if (s.emplace(a, b).second) {
        res.push_back({a, b, c});
      }
    }
    auto res1 = solution(res);
    auto res2 = solution2(res);
    if (res1 != res2) {
      cout << N << '\n';
      for (auto&e : res) {
        cout << e[0] << " " << e[1] << " " << e[2] << '\n';
      }
      debug(res1);
      debug(res2);
      break;
    }
  }
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