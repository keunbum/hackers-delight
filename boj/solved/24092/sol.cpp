#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int MAXN = (int) 1e4;

int n;
int equal_cnt = 0;
int A[MAXN], B[MAXN];

void Test() {
  if (equal_cnt == n) {
    cout << 1 << '\n';
    exit(0);
  }
}

void Swap(int i, int j) {
  equal_cnt -= (A[i] == B[i]);
  equal_cnt -= (A[j] == B[j]);
  swap(A[i], A[j]);
  equal_cnt += (A[i] == B[i]);
  equal_cnt += (A[j] == B[j]);
  Test();
}

int partition(int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) { 
    if (A[j] <= x) {
      Swap(++i, j);
    }
  }
  if (i + 1 != r) {
    Swap(i + 1, r);
  }
  return i + 1;
}

void quick_sort(int p, int r) {
  if (p < r) {
    int q = partition(p, r);
    quick_sort(p, q - 1);
    quick_sort(q + 1, r);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
    equal_cnt += (A[i] == B[i]);
  }
  Test();
  quick_sort(0, n - 1);
  cout << 0 << '\n';
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