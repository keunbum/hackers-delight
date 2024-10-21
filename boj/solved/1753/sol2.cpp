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

struct Edge {
  int to;
  int dist;

  Edge(int to, int dist) : to(to), dist(dist) {}

  bool operator<(const Edge& rhs) const {
    return dist > rhs.dist;
  }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int inf = (int)1e9;
	int n, m;
	cin >> n >> m;
	int st;
	cin >> st;
	--st;
	vector<vector<Edge>> g(n);
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		--x; --y;
		g[x].emplace_back(y, z);
	}
	priority_queue<Edge> s;
	vector<int> dist(n, inf);
	dist[st] = 0;
	s.emplace(st, dist[st]);
	while (!s.empty()) {
		int expected = s.top().dist;
        int v = s.top().to;
        s.pop();
		if (expected != dist[v]) {
			continue;
		}
		for (auto& p : g[v]) {
			int u = p.to;
            int w = p.dist;
			if (dist[v] + w < dist[u]) {
				dist[u] = dist[v] + w;
				s.emplace(u, dist[u]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << (dist[i] == inf ? "INF" : to_string(dist[i])) << '\n';
	}
	return 0;
}