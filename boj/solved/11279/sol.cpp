#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

// 0-based
template <typename T, size_t MAX_SIZE, class C = function<bool(const T&, const T&)>>
class pq {
private:
  int n;
  C comp;
  T a[MAX_SIZE];

public:
  pq() : pq(less<T>()) {
  }

  pq(const C& c) : n(0), comp(c) {}

  bool empty() const {
    return n == 0;
  }

  const int& size() const {
    return n;
  }

  const T& top() const {
    return a[0];
  }

  void push(const T& val) {
    int i = n;
    int pr = (i - 1) / 2;
    while (i != 0 && comp(a[pr], val)) {
      a[i] = a[pr];
      i = pr;
      pr = (i - 1) / 2;
    }
    a[i] = val;
    ++n;
  } 

  T pop() {    
    swap(a[0], a[n - 1]);
    --n;
    int i = 0;
    while (true) {
      int l = i << 1 | 1;
      int r = l + 1;
      int j = i;
      if (l < n && comp(a[j], a[l])) j = l;
      if (r < n && comp(a[j], a[r])) j = r;
      if (i == j) break;
      swap(a[j], a[i]);
      i = j;
    }
    return a[n];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Cmp = [&](int i, int j) {
    return i < j;
  };
  pq<int, int(1e5)> s(Cmp);
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
  * don't get excited. keep calm
  
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