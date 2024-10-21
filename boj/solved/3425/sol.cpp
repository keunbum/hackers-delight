#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  /*
  cout << "13 / -4 = " << 13 / -4 << '\n';
  cout << "-13 / 4 = " << -13 / 4 << '\n';
  cout << "-13 % -4 = " << -13 / -4 << '\n';
  cout << "13 % -4 = " << 13 % -4 << '\n';
  cout << "-13 % 4 = " << -13 % 4 << '\n';
  cout << "-13 % -4 = " << -13 % -4 << '\n';
  */
  while (true) {
    vector<string> cmds;
    vector<int> xs;
    while (true) {
      string cmd;
      cin >> cmd;
      if (cmd == "QUIT") {
        return 0;
      }
      if (cmd == "END") {
        break;
      }
      int x = -1;
      if (cmd == "NUM") {
        cin >> x;
      }
      xs.push_back(x);
      cmds.push_back(cmd);
    }
    int n;
    cin >> n;
    while (n--) {
      int init_v;
      cin >> init_v;
      vector<int> stk;
      stk.push_back(init_v);
      bool ok = true;
      for (int id = 0; id < (int) cmds.size(); id++) {
        if (cmds[id] == "NUM") {
          int x = xs[id];
          assert(x != -1);
          stk.push_back(x);
        }
        if (cmds[id] == "POP") {
          if (stk.empty()) {
            ok = false;
            break;
          }
          stk.pop_back();
        }
        if (cmds[id] == "INV") {
          if (stk.empty()) {
            ok = false;
            break;
          }
          stk.back() *= -1;
        }
        if (cmds[id] == "DUP") {
          if (stk.empty()) {
            ok = false;
            break;
          }
          stk.push_back(stk.back());
        }
        if (cmds[id] == "SWP") {
          if (stk.size() < 2) {
            ok = false;
            break;
          }
          swap(stk[stk.size() - 1], stk[stk.size() - 2]);
        }
        if (cmds[id] == "ADD") {
          if (stk.size() < 2) {
            ok = false;
            break;
          }
          int new_v = stk[stk.size() - 2] + stk[stk.size() - 1];
          if (abs(new_v) > inf) {
            ok = false;
            break;
          }
          stk.pop_back();
          stk.back() = new_v;
        }
        if (cmds[id] == "SUB") {
          if (stk.size() < 2) {
            ok = false;
            break;
          }
          int new_v = stk[stk.size() - 2] - stk[stk.size() - 1];
          if (abs(new_v) > inf) {
            ok = false;
            break;
          }
          stk.pop_back();
          stk.back() = new_v;
        }
        if (cmds[id] == "MUL") {
          if (stk.size() < 2) {
            ok = false;
            break;
          }
          long long new_v = (long long) stk[stk.size() - 2] * stk[stk.size() - 1];
          if (abs(new_v) > (long long) inf) {
            ok = false;
            break;
          }
          stk.pop_back();
          stk.back() = (int) new_v;
        }
        if (cmds[id] == "DIV") {
          if (stk.size() < 2 || stk[stk.size() - 1] == 0) {
            ok = false;
            break;
          }
          int new_v = stk[stk.size() - 2] / stk[stk.size() - 1];
          if (abs(new_v) > inf) {
            ok = false;
            break;
          }
          stk.pop_back();
          stk.back() = new_v;
        }
        if (cmds[id] == "MOD") {
          if (stk.size() < 2 || stk[stk.size() - 1] == 0) {
            ok = false;
            break;
          }
          int new_v = stk[stk.size() - 2] % stk[stk.size() - 1];
          if (abs(new_v) > inf) {
            ok = false;
            break;
          }
          stk.pop_back();
          stk.back() = new_v;
        }
      }
      if (stk.size() != 1) {
        ok = false;
      }
      if (!ok) {
        cout << "ERROR" << '\n';
        continue;
      }
      assert(abs(stk.back()) <= inf);
      cout << stk.back() << '\n';
    }
    cout << '\n';
  }
  return 0;
}

/* read it as if you were wrong once. --> "why is this wrong??"

 * basic strategy:
  * don't be obsessed with speed or memory when the input is small compared to limit
  * internalization of problem statements
  * simplify. a step-by-step approach
  * readability is important
  * don't lose your pace. keep calm
  
 * stuff you should look for
  * 0-based or 1-based?
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * WRITE STUFF DOWN
  * DON'T GET STUCK ON ONE APPROACH
  
 * after solving the problem
  * consider whether there is another way.
  * reduce memory, time, codes, ...
*/