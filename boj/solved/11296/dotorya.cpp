#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		db v = 0;
		char c1[5], c2[5], c3[5];
		scanf("%lf %s %s %s", &v, c1, c2, c3);

		if (c1[0] == 'R') v *= 0.55;
		if (c1[0] == 'G') v *= 0.70;
		if (c1[0] == 'B') v *= 0.80;
		if (c1[0] == 'Y') v *= 0.85;
		if (c1[0] == 'O') v *= 0.9;
		if (c1[0] == 'W') v *= 0.95;

		if (c2[0] == 'C') v *= 0.95;
		if (c3[0] == 'C') printf("$%.1lf0\n", v + (db)ERR);
		else printf("$%.2lf\n", v + (db)ERR);
	}
	return 0;
}