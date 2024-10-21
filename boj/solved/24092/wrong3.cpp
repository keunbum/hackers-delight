#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

vector<int> A, B;
long long compare_cnt = -1;

void Exit(int res) {
  debug(compare_cnt);
  cout << res << '\n';
  debug(clock() * 1.0 / CLOCKS_PER_SEC);
  exit(0);
}

bool Check(int b, int e) {
    for (int i = b; i <= e; i++) {
#ifdef LOCAL
        compare_cnt += 1;
#endif
        if (A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

int partition(int p, int r) {
    if (A[r] == r + 1) {
        if (B[r] != A[r]) {
          debug(A, p, r, B[r], r + 1, "partition mismatch");
          Exit(0);
        }
        return r;
    } 
    int i = p - 1;
    for (int j = p; j < r; j++) {  // j는 아직 정해지지 않은 원소들의 시작 지점
        if (A[j] < A[r]) {
            i += 1;
            if (A[i] > A[j]) {
                swap(A[i], A[j]); // i값 증가 후 A[i] <-> A[j] 교환
                if (Check(p, r)) {
                    return -1;
                }
            }
        }
    }
    swap(A[i + 1], A[r]);
//    debug(p, r, i + 1, A[i + 1], B[i + 1], i + 2);
    if (B[i + 1] != A[i + 1]) {
        debug(A, p, r, i, B[i + 1], A[i + 1], "partition mismatch");
        Exit(0);
    }
    return Check(p, r) ? -1 : i + 1;
}

bool quick_sort(int p, int r) { // A[p..r]을 오름차순 정렬한다.
    if (p > r) {
        return true;
    }
    if (p == r) {
        if (A[p] != B[p]) {
          debug(A, p, r, A[p], B[p], "partition mismatch");
          Exit(0);
        }
        return true;
    }
    int q = partition(p, r);  // 분할    
//    debug("partition =>", p, r, A, q);
    if (q == -1) {
        return true;
    }
    return quick_sort(p, q - 1) && quick_sort(q + 1, r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  A.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  B.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  Exit(Check(0, n - 1) || quick_sort(0, n - 1));
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't get excited. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN (Don't be stubborn)
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/