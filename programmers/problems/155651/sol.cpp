#include <string>
#include <vector>
#include <cstdio>
#include <array>
#include <algorithm>

using namespace std;

int Encode(string& s) {
    int h, m;
    sscanf(s.data(), "%d:%d", &h, &m);
    return 60 * h + m;
}

int solution(vector<vector<string>> book_time) {
    int n = int(book_time.size());
    vector<array<int, 2>> a(n + n);
    for (int i = 0; i < n; ++i) {
        a[i + i] = {Encode(book_time[i][0]), +1};
        a[i + i + 1] = {Encode(book_time[i][1]) + 10, -1};
    }
    sort(a.begin(), a.end());
    int bal = 0;
    int ret = 0;
    for (auto& [_, type] : a) {
        bal += type;
        ret = max(ret, bal);
    }
    return ret;
}
