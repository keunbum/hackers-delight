#include <bits/stdc++.h>

using namespace std;

struct node {
  char ch;
  node* l;
  node* r;

  node(char _ch, node* _l = nullptr, node* _r = nullptr) : ch(_ch), l(_l), r(_r) {}
};

node* add(node* ptr, node* ntr) {
  if (ptr->r != nullptr) {
    ptr->r->l = ntr;
    ntr->r = ptr->r;
  }
  ptr->r = ntr;
  ntr->l = ptr;
  return ntr;
}

node* remove(node* ptr) {
  if (ptr->r != nullptr) {
    ptr->r->l = ptr->l;
  }
  ptr->l->r = ptr->r;
  node* ret = ptr->l;
  delete ptr;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    node* ptr = new node(' ');
    for (char ch : s) {
      if (ch == '-') {
        if (ptr->l != nullptr) {
          ptr = remove(ptr);
        }
        continue;
      }
      if (ch == '<') {
        if (ptr->l != nullptr) {
          ptr = ptr->l;
        }
        continue;
      }
      if (ch == '>') {
        if (ptr->r != nullptr) {
          ptr = ptr->r;
        }
        continue;
      }
      ptr = add(ptr, new node(ch));
    }
    string ans;
    while (ptr->l != nullptr) ptr = ptr->l;
    while (ptr->r != nullptr) {
      ans += ptr->r->ch;
      ptr = remove(ptr->r);
    }
    delete ptr;
    cout << ans << '\n';
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. deep breathing. keep calm
  
 * stuff you should look for
  * performance or safety?
  * local or global?
  * 0-based or 1-based?
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