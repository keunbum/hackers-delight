#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* 실제 코딩 테스트 보는 것처럼 프로그래머스 에디터에서 풀이 */

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    --col;
    sort(data.begin(), data.end(), [&](auto& ci, auto& cj) {
        return make_pair(ci[col], ~ci[0]) < make_pair(cj[col], ~cj[0]);
    });
    int ret = 0;
    int n = int(data.size());
    int m = int(data[0].size());
    for (int i = row_begin - 1; i < row_end; ++i) {
        int s = 0;
        for (int j = 0; j < m; ++j) {
            s += data[i][j] % (i + 1);
        }
        ret ^= s;
    }
    return ret;
}