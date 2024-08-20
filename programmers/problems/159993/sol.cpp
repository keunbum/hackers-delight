#include <string>
#include <vector>

using namespace std;

int solution(vector<string> grid) {
    int h = int(grid.size());
    int w = int(grid[0].size());
    auto BFS = [&](int si, int sj, int ei, int ej) {
        vector<vector<int>> dist(h, vector<int>(w, -1));
        dist[si][sj] = 0;
        vector<pair<int, int>> que{{si, sj}};
        for (int b = 0; b < int(que.size()); ++b) {
            auto [mi, mj] = que[b];
            for (int dir = 0; dir < 4; ++dir) {
                const int di[] = {0, 1, 0, -1};
                const int dj[] = {-1, 0, 1, 0};
                int ni = mi + di[dir];
                int nj = mj + dj[dir];
                if (ni >= 0 && nj >= 0 && ni < h && nj < w && grid[ni][nj] != 'X' && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[mi][mj] + 1;
                    que.emplace_back(ni, nj);
                }
            }
        }
        return dist[ei][ej];
    };
    int si = -1, sj = -1, li = -1, lj = -1, ei = -1, ej = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 'S') si = i, sj = j;
            if (grid[i][j] == 'L') li = i, lj = j;
            if (grid[i][j] == 'E') ei = i, ej = j;
        }
    }
    int ans1 = BFS(si, sj, li, lj);
    int ans2 = BFS(li, lj, ei, ej);
    return (ans1 == -1 || ans2 == -1) ? -1 : ans1 + ans2;
}
