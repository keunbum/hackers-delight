#include <bits/stdc++.h>

using namespace std;

const int S = 1;
const int E = 33;

int score[55], nxt[55], aux[55];
int dice[10];
int where[4];

void Init() {
  score[1] = 0;
  score[2] = 2;
  score[3] = 4;
  score[4] = 6;
  score[5] = 8;
  score[6] = 10;
  score[7] = 12;
  score[8] = 14;
  score[9] = 16;
  score[10] = 18;
  score[11] = 20;
  score[12] = 22;
  score[13] = 24;
  score[14] = 26;
  score[15] = 28;
  score[16] = 30;
  score[17] = 32;
  score[18] = 34;
  score[19] = 36;
  score[20] = 38;
  score[21] = 40;
  score[22] = 13;
  score[23] = 16;
  score[24] = 19;
  score[25] = 22;
  score[26] = 24;
  score[27] = 25;
  score[28] = 28;
  score[29] = 27;
  score[30] = 26;
  score[31] = 30;
  score[32] = 35;
  score[33] = 0;

  nxt[1] = 2;
  nxt[2] = 3;
  nxt[3] = 4;
  nxt[4] = 5;
  nxt[5] = 6;
  nxt[6] = 7;
  nxt[7] = 8;
  nxt[8] = 9;
  nxt[9] = 10;
  nxt[10] = 11;
  nxt[11] = 12;
  nxt[12] = 13;
  nxt[13] = 14;
  nxt[14] = 15;
  nxt[15] = 16;
  nxt[16] = 17;
  nxt[17] = 18;
  nxt[18] = 19;
  nxt[19] = 20;
  nxt[20] = 21;
  nxt[21] = 33;
  nxt[22] = 23;
  nxt[23] = 24;
  nxt[24] = 27;
  nxt[25] = 26;
  nxt[26] = 27;
  nxt[27] = 31;
  nxt[28] = 29;
  nxt[29] = 30;
  nxt[30] = 27;
  nxt[31] = 32;
  nxt[32] = 21;
  nxt[33] = 33;

  aux[6] = 22;
  aux[11] = 25;
  aux[16] = 28;

  for (int i = 0; i < 4; ++i) {
    where[i] = S;
  }
}

int ans;

void DFS(int v, int cur) {
  if (v == 10) {
    ans = max(ans, cur);
    return;
  }
  for (int i = 0; i < 4; ++i) {
    if (where[i] == E) {
      continue;
    }
    int now = where[i];
    int rep = dice[v];
    if (aux[now] != 0) {
      now = aux[now];
      rep -= 1;
    }
    while (rep--) {
      now = nxt[now];
    }
    bool ok = true;
    for (int j = 0; j < 4; ++j) {
      ok &= where[j] != now;
    }
    if (now == E || ok) {
      int was = where[i];
      where[i] = now;
      DFS(v + 1, cur + score[now]);
      where[i] = was;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  /*
  int i = 1;
  string s0, s1;
  while (true) {
    int x, y;
    cin >> x >> y;
    if (x == -1) break;
    s0 += "score[" + to_string(i) + "] = " + to_string(x) + ";\n";
    s1 += "nxt[" + to_string(i) + "] = " + to_string(y) + ";\n";
    i += 1;
  }
  string s2;
  while (true) {
    int x, y;
    cin >> x >> y;
    if (x == -1) break;
    s2 += "aux[" + to_string(x) + "] = " + to_string(y) + ";\n";
  }
  cout << s0 << '\n' << s1 << '\n' << s2 << '\n';
  */
  Init();
  for (int i = 0; i < 10; ++i) {
    cin >> dice[i];
  }
  ans = 0;
  DFS(0, 0);
  cout << ans << '\n';
  return 0;
}