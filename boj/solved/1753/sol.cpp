#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <tuple>
#include <functional>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int inf = (int)1e9;
	int n, m;
	cin >> n >> m;
	int st;
	cin >> st;
	--st;
	vector<vector<pair<int, int>>> g(n);
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		--x; --y;
		g[x].emplace_back(y, z);
	}
	priority_queue<pair<int, int>> s;
	vector<int> dist(n, inf);
	dist[st] = 0;
	s.emplace(~dist[st], st);
	while (!s.empty()) {
		int expected, v;
		tie(expected, v) = s.top();
		s.pop();
		if (~expected != dist[v]) {
			continue;
		}
		for (auto& p : g[v]) {
			int u, w;
			tie(u, w) = p;
			if (dist[v] + w < dist[u]) {
				dist[u] = dist[v] + w;
				s.emplace(~dist[u], u);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << (dist[i] == inf ? "INF" : to_string(dist[i])) << '\n';
	}
	return 0;
}