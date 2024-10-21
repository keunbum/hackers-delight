#include<cstdio>
#include<algorithm>
using namespace std;
int A[4097][4096];
int n, K;
int main() {
	int i, j, k;
	A[1][0] = 1;
	A[2][0] = A[2][1] = 1;
	for (i = 2; i <= 12; i++) {
		for (j = (1 << (i - 1)) + 1; j <= (1 << i); j++) {
			for (k = 0; k < (1 << i); k++) {
				A[j][k] = !A[(1 << i) - j][k];
			}
		}
	}
	scanf("%d%d", &n,&K);
	puts("YES");
	for (i = 0; i < (1 << n); i++)if (A[K][i])printf("%d ", i);

}