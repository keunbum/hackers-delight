#include <bits/stdc++.h>

using namespace std;

const int MAX = 600010;

char stka[MAX];
char stkb[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	getline(cin, s);
	int ta = (int) s.size();
	for (int i = 0; i < ta; i++) {
		stka[i] = s[i];
	}
	int tb = 0;
	auto Move = [&](int d) {
		if (ta + d < 0 || tb - d < 0) {
			return;
		}
		if (d > 0) {
			stka[ta++] = stkb[tb - 1];
			tb--;
		} else {
			stkb[tb++] = stka[ta - 1];
			ta--;
		}
	};
	auto Delete = [&]() {
		if (ta > 0) {
			ta--;
		}
	};
	auto Insert = [&](char c) {
		stka[ta++] = c;
	};
	auto Print = [&]() {
		stka[ta] = 0;
		cout << stka;
		for (int i = tb - 1; ~i; i--) {
			cout << stkb[i];
		}
		cout << '\n';
	};
	int n;
	cin >> n;
	while (n--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			Move(-1);
		} else
		if (cmd == 'D') {
			Move(1);
		} else
		if (cmd == 'B') {
			Delete();
		} else
		if (cmd == 'P') {
			char c;
			cin >> c;
			Insert(c);
		}
	}
	Print();
	return 0;
}
