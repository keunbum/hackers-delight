#include <string>
#include <vector>
#include <cstdio>
#include <array>
#include <algorithm>
#include <queue>

using namespace std;

int Encode(string& s) {
    int h, m;
    sscanf(s.data(), "%d:%d", &h, &m);
    return 60 * h + m;
}

int solution(vector<vector<string>> book_time) {
    int n = int(book_time.size());
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = Encode(book_time[i][j]) + j * 10;
        }
    }
    sort(a.begin(), a.end());
    priority_queue<int> s;
    int ret = 0;
    for (auto& [beg, end] : a) {
        while (!s.empty() && ~s.top() <= beg) {
            s.pop();
        }
        s.push(~end);
        ret = max(ret, int(s.size()));
    }
    return ret;
}
