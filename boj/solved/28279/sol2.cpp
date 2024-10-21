#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.h"
#else
#define debug(...) void(0)
#endif

const int MAXN = (int) 1e6;

int deq[MAXN];

int Inc(int i) { return ++i == MAXN ? 0 : i; }
int Dec(int i) { return --i == -1 ? MAXN - 1 : i; }

int b = 0, e = 1, sz = 0;

int GetFront() { return deq[Inc(b)]; }
int GetBack() { return deq[Dec(e)]; } 

void PushFront(int x) {
  deq[b] = x;
  b = Dec(b);
  sz += 1;
}

void PushBack(int x) {
  deq[e] = x;
  e = Inc(e);
  sz += 1;
}

int PopFront() {
  sz -= 1;
  return deq[b = Inc(b)];
}

int PopBack() {
  sz -= 1;
  return deq[e = Dec(e)];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int c;
    cin >> c;
    if (c <= 2) {
      int x;
      cin >> x;
      c & 1 ? PushFront(x) : PushBack(x);
    } else
    if (c <= 4) cout << (sz == 0 ? -1 : (c & 1 ? PopFront() : PopBack())) << '\n'; else
    if (c == 5) cout << sz << '\n'; else
    if (c == 6) cout << (sz == 0) << '\n'; else
    if (c <= 8) cout << (sz == 0 ? -1 : (c & 1 ? GetFront() : GetBack())) << '\n';
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  
 * stuff you should look for
  * 0-based or 1-based?
  * off-by-one error
  * int overflow, array bounds (habituation of assert and debug)
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH (feat. BFS)
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/