// writer: wheeinjj417
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool PrimeTable[1000001] = { 0, };
	int root = (int)sqrt(1000000);
	for (int i = 2; i <= root; i++) {
		if (PrimeTable[i]) continue;
		for (int j = i * i; j <= 1000000; j += i) PrimeTable[j] = 1;
	}

	while (1) {
		int n;  cin >> n; if (!n) break;

		bool Goldbach = false;
		for (int i = 3; i < n/2; i+=2) {
			if (!PrimeTable[i] && !PrimeTable[n - i]) {
				cout << n << " = " << i << " + " << n - i << '\n';
				Goldbach = true;
				break;
			}
		}
		if (!Goldbach) cout << "Goldbach's conjecture is wrong." << '\n';
	}

	return 0;
}