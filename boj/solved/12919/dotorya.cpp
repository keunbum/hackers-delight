#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char S[55];
char T[55];
bool dp[2][55][55];

int main() {
	int i, j;
	scanf("%s %s", S, T);
	int L1 = strlen(S), L2 = strlen(T);

	for (i = 0; i <= L2 - L1; i++) {
		for (j = 0; j < L1; j++) if (S[j] != T[i + j]) break;
		if (j >= L1) dp[0][i][i + L1 - 1] = true;

		for (j = 0; j < L1; j++) if (S[j] != T[i + L1 - 1 - j]) break;
		if (j >= L1) dp[1][i][i + L1 - 1] = true;
	}

	for (i = L1; i < L2; i++) {
		for (j = 0; j < L2 - i; j++) {
			int s = j, e = i + j;
			
			dp[0][s][e] = false;
			if (dp[0][s][e - 1] && T[e] == 'A') dp[0][s][e] = true;
			if (dp[1][s + 1][e] && T[s] == 'B') dp[0][s][e] = true;

			dp[1][s][e] = false;
			if (dp[1][s + 1][e] && T[s] == 'A') dp[1][s][e] = true;
			if (dp[0][s][e - 1] && T[e] == 'B') dp[1][s][e] = true;
		}
	}
	return !printf("%d\n", (int)dp[0][0][L2 - 1]);
}