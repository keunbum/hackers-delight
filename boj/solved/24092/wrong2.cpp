#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

const int MAXN = (int) 1e4;

int A[MAXN], B[MAXN];

void Exit(int result) {
  cout << result << '\n';
  exit(0);
}

bool IsEqual(int p, int r) {
  for (int i = p; i <= r; i++) {
    if (A[i] != B[i]) {
      return false;
    }
  }
  return true;
}

int partition(int p, int r) {
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j] < A[r]) {
      i += 1;
      if (A[i] > A[j]) {
        swap(A[i], A[j]);
        if (IsEqual(p, r)) {
          return -1;
        }
      }
    }
  }
  swap(A[i + 1], A[r]);
  return IsEqual(p, r) ? -1 : i + 1;
}

bool quick_sort(int p, int r) {
  if (p > r) {
    return true;
  }
  int q = partition(p, r);
  if (q == -1) {
    return true;
  }
  if (A[q] != B[q]) {
    return false;
  }
  if (IsEqual(p, q - 1)) {
    return IsEqual(q + 1, r) || quick_sort(q + 1, r);
  }
  return quick_sort(p, q - 1) && ((!is_sorted(A + p, A + q - 1) && IsEqual(q + 1, r)) || quick_sort(q + 1, r));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  cout << (IsEqual(0, n - 1) || quick_sort(0, n - 1)) << '\n';
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