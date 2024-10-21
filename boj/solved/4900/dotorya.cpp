//*
#include <algorithm>
#include <iostream>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

char tmp[105];

int ch[130];
int x[15] = { 63, 10, 93, 79, 106, 103, 119, 11, 127, 107 };
vector <int> ans;
int main() {
	ch[63] = 0;
	ch[10] = 1;
	ch[93] = 2;
	ch[79] = 3;
	ch[106] = 4;
	ch[103] = 5;
	ch[119] = 6;
	ch[11] = 7;
	ch[127] = 8;
	ch[107] = 9;
	while (1) {
		scanf("%s", tmp);
		if (tmp[0] == 'B') break;
		
		int a = 0, b = 0, i;
		for (i = 0; tmp[i] != '+'; i+=3) {
			int t = (tmp[i] - '0') * 100 + (tmp[i + 1] - '0') * 10 + (tmp[i + 2] - '0');
			a *= 10;
			a += ch[t];
		}
		i++;
		for (; tmp[i] != '='; i += 3) {
			int t = (tmp[i] - '0') * 100 + (tmp[i + 1] - '0') * 10 + (tmp[i + 2] - '0');
			b *= 10;
			b += ch[t];
		}
		int c = a + b;
		while (c != 0) {
			ans.push_back(c % 10);
			c /= 10;
		}

		printf("%s", tmp);
		while (!ans.empty()) {
			printf("%03d", x[ans.back()]);
			ans.pop_back();
		}
		printf("\n");
		for (i = 0; tmp[i] != 0; i++) tmp[i] = 0;
	}
	return 0;
}
//*/

