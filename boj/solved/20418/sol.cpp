#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "template/debug.hpp"
#else
#define debug(...) void(0)
#endif

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
 
class node {
public:
  int id;
  node* l;
  node* r;
  node* p;
  bool rev;
  int sz;
  // declare extra variables:
  int P;
  tuple<int, int, int, int> sort_by; // solved, total_penalty, last_correct_submit, order
 
  node(int _id) {
    id = _id;
    l = r = p = nullptr;
    rev = false;
    sz = 1;
    // init extra variables:
    P = rng();
    sort_by = make_tuple(0, 0, -1, -1);
  }
 
  void unsafe_reverse() {
    rev ^= 1;
    swap(l, r);
    pull();
  }
 
  // apply changes:
  void unsafe_apply() {
    
  }
 
  void push() {
    if (rev) {
      if (l != nullptr) {
        l->unsafe_reverse();
      }
      if (r != nullptr) {
        r->unsafe_reverse();
      }
      rev = 0;
    }
    // now push everything else:
 
  }
 
  void pull() {
    sz = 1;
    // now init from self:
 
    if (l != nullptr) {
      l->p = this;
      sz += l->sz;
      // now pull from l:
 
    }
    if (r != nullptr) {
      r->p = this;
      sz += r->sz;
      // now pull from r:
 
    }
  }
};
 
void debug_node(node* v, string pref = "") {
  #ifdef LOCAL
    if (v != nullptr) {
      debug_node(v->r, pref + "#");
      cerr << pref << "" << "" << v->id + 1 << "(" << to_string(v->sort_by) << ")" << '\n';
      debug_node(v->l, pref + "#");
    } else {
      cerr << pref << "" << " " << "nullptr" << '\n';
    }
  #endif
}

namespace treap {
 
pair<node*, int> find(node* v, const function<int(node*)> &go_to) {
  // go_to returns: 0 -- found; -1 -- go left; 1 -- go right
  // find returns the last vertex on the descent and its go_to
  if (v == nullptr) {
    return {nullptr, 0};
  }
  int dir;
  while (true) {
    v->push();
    dir = go_to(v);
    if (dir == 0) {
      break;
    }
    node* u = (dir == -1 ? v->l : v->r);
    if (u == nullptr) {
      break;
    }
    v = u;
  }
  return {v, dir};
}
 
node* get_leftmost(node* v) {
  return find(v, [&](node*) { return -1; }).first;
}
 
node* get_rightmost(node* v) {
  return find(v, [&](node*) { return 1; }).first;
}
 
node* get_kth(node* v, int k) { // 0-indexed
  pair<node*, int> p = find(v, [&](node* u) {
    if (u->l != nullptr) {
      if (u->l->sz > k) {
        return -1;
      }
      k -= u->l->sz;
    }
    if (k == 0) {
      return 0;
    }
    k--;
    return 1;
  });
  return (p.second == 0 ? p.first : nullptr);
}
 
int get_position(node* v) { // 0-indexed
  int k = (v->l != nullptr ? v->l->sz : 0);
  while (v->p != nullptr) {
    if (v == v->p->r) {
      k++;
      if (v->p->l != nullptr) {
        k += v->p->l->sz;
      }
    }
    v = v->p;
  }
  return k;
}
 
node* get_bst_root(node* v) {
  while (v->p != nullptr) {
    v = v->p;
  }
  return v;
}
 
pair<node*, node*> split(node* v, const function<bool(node*)> &is_right) {
  if (v == nullptr) {
    return {nullptr, nullptr};
  }
  v->push();
  if (is_right(v)) {
    pair<node*, node*> p = split(v->l, is_right);
    if (p.first != nullptr) {
      p.first->p = nullptr;
    }
    v->l = p.second;
    v->pull();
    return {p.first, v};
  } else {
    pair<node*, node*> p = split(v->r, is_right);
    v->r = p.first;
    if (p.second != nullptr) {
      p.second->p = nullptr;
    }
    v->pull();
    return {v, p.second};
  }
}
 
pair<node*, node*> split_leftmost_k(node* v, int k) {
  return split(v, [&](node* u) {
    int left_and_me = (u->l != nullptr ? u->l->sz : 0) + 1;
    if (k >= left_and_me) {
      k -= left_and_me;
      return false;
    }
    return true;
  });
}
 
node* merge(node* v, node* u) {
  if (v == nullptr) {
    return u;
  }
  if (u == nullptr) {
    return v;
  }
  if (v->P > u->P) {
//    if (rng() % (v->sz + u->sz) < (unsigned int) v->sz) {
    v->push();
    v->r = merge(v->r, u);
    v->pull();
    return v;
  } else {
    u->push();
    u->l = merge(v, u->l);
    u->pull();
    return u;
  }
}
 
int count_left(node* v, const function<bool(node*)> &is_right) {
  if (v == nullptr) {
    return 0;
  }
  v->push();
  if (is_right(v)) {
    return count_left(v->l, is_right);
  }
  return (v->l != nullptr ? v->l->sz : 0) + 1 + count_left(v->r, is_right);
}
 
node* add(node* r, node* v, const function<bool(node*)> &go_left) {
  pair<node*, node*> p = split(r, go_left);
  return merge(p.first, merge(v, p.second));
}
 
node* remove(node* v) { // returns the new root
  v->push();
  node* x = v->l;
  node* y = v->r;
  node* p = v->p;
  v->l = v->r = v->p = nullptr;
  v->push();
  v->pull(); // now v might be reusable...
  node* z = merge(x, y);
  if (p == nullptr) {
    if (z != nullptr) {
      z->p = nullptr;
    }
    return z;
  }
  if (p->l == v) {
    p->l = z;
  }
  if (p->r == v) {
    p->r = z;
  }
  while (true) {
    p->push();
    p->pull();
    if (p->p == nullptr) {
      break;
    }
    p = p->p;
  }
  return p;
}
 
node* next(node* v) {
  if (v->r == nullptr) {
    while (v->p != nullptr && v->p->r == v) {
      v = v->p;
    }
    return v->p;
  }
  v->push();
  v = v->r;
  while (v->l != nullptr) {
    v->push();
    v = v->l;
  }
  return v;
}
 
node* prev(node* v) {
  if (v->l == nullptr) {
    while (v->p != nullptr && v->p->l == v) {
      v = v->p;
    }
    return v->p;
  }
  v->push();
  v = v->l;
  while (v->r != nullptr) {
    v->push();
    v = v->r;
  }
  return v;
}
 
int get_size(node* v) {
  return (v != nullptr ? v->sz : 0);
}
 
template<typename... T>
void apply(node* v, T... args) {
  v->unsafe_apply(args...);
}
 
void reverse(node* v) {
  v->unsafe_reverse();
}
 
}  // namespace treap

using namespace treap;

int Encode(const string& s) {
  return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  node* root = nullptr;
  vector<int> ret(n, 0);
  vector<node*> ptrs(n, nullptr);
  vector<vector<tuple<int, int, int, int>>> queries(n);
  vector<pair<int, int>> last_submit(n, {-1, -1});
  auto Update = [&](node* v, int t, int s, int i) {
    debug("Update():", v->id + 1);
    last_submit[v->id] = max(last_submit[v->id], make_pair(t, i));
    get<0>(v->sort_by) += 1;
    get<1>(v->sort_by) += t + (s - 1) * 20;
    get<2>(v->sort_by) = last_submit[v->id].first;
    get<3>(v->sort_by) = last_submit[v->id].second;
    auto x = split(root, [&](node* u) {
      auto[ua, ub, uc, ud] = u->sort_by;
      auto[va, vb, vc, vd] = v->sort_by;
      return make_tuple(ua, ~ub, ~uc, ~ud) > make_tuple(va, ~vb, ~vc, ~vd);
    });
    root = merge(merge(x.first, v), x.second);
    debug("root");
    debug_node(root);
  };    
  for (int i = 0; i < m; i++) {
    string s_time;
    int id, p, s;
    cin >> s_time >> id >> p >> s;
    --id; --p;
    int t = Encode(s_time);
    if (t > Encode("03:00")) {
      queries[id].emplace_back(t, p, s, i);
      continue;
    }
    last_submit[id] = make_pair(t, i);
    node* v = ptrs[id];
    if (v == nullptr) {
      ptrs[id] = new node(id);
      v = ptrs[id];
    } else {
      root = remove(v);
    }
    Update(v, t, s, i);
  }
  for (auto& q : queries) {
    sort(q.begin(), q.end(), [&](auto& ti, auto& tj) {
      return get<1>(ti) > get<1>(tj);
    });
  }
  vector<int> rank(n);
  int order = n;
  auto GetNext = [&](node* v) {
    while (v != nullptr && queries[v->id].empty()) {
      node* u = v;
      v = next(v);
      rank[u->id] = order--;
      root = remove(u);
    }
    return v;
  };    
  debug("Freezing");
  while (true) {
    node* least = GetNext(get_leftmost(root));
    if (least == nullptr) {
      break;
    }
    debug(queries);
    debug(ret);
    auto[t, p, s, i] = queries[least->id].back();
    debug(least->id + 1, t, p, s, i);
    int old_rank = get_position(least);
    root = remove(least);
    Update(least, t, s, i);
    int new_rank = get_position(least);
    debug(old_rank, new_rank);
    ret[least->id] += max(0, new_rank - old_rank);
    queries[least->id].pop_back();
  }
  debug(ret);
  debug(rank);
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  int ans = (int) (min_element(ord.begin(), ord.end(), [&](int i, int j) {
    return ret[i] > ret[j] || (ret[i] == ret[j] && rank[i] < rank[j]);
  }) - ord.begin()) + 1;
  cout << ans << '\n';
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * keep calm
  
 * stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
  * what is my weakness that need to be addressed by solving this problem?
*/