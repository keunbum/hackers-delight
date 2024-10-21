#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

template<typename T, size_t N, class Compare = less<T>>
class static_pq {
private:
  int n;
  T a[N];
  Compare comp;

  // [b, e)
  void up_heap(int b, int e) {
    int i = e - 1;
    int pr = (i - 1) / 2;
    while (i != 0 && pr >= b && comp(a[pr], a[i])) {
      swap(a[pr], a[i]);
      i = pr;
      pr = (i - 1) / 2;
    }
  }

  // [b, e)
  void down_heap(int b, int e) {
    --e;
    int i = b;
    while (true) {
      int l = i << 1 | 1;
      int r = l + 1;
      int j = i;
      if (l < e && comp(a[j], a[l])) j = l;
      if (r < e && comp(a[j], a[r])) j = r;
      if (i == j) break;
      swap(a[i], a[j]);
      i = j;
    } 
  }
public:
  static_pq(const Compare& _comp = Compare()) : comp(_comp) {}

  inline bool empty() const { return n == 0; }
  inline const T& top() const { return a[0]; }
  inline void init() { n = 0; }

  void push(const T& x) {
    a[n++] = x;
    up_heap(0, n);
  }

  T pop() {
    swap(a[0], a[n - 1]);
    down_heap(0, n);
    return a[--n];
  }
};

static_pq<int, (int)1e5> s; 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  s.init();
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    if (x == 0) {
      if (s.empty()) {
        cout << 0 << '\n';
      } else {
        cout << s.top() << '\n';
        s.pop();
      }
    } else {
      s.push(x);
    }
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * think rationally. keep calm
  
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