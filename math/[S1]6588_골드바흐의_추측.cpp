//에라토스테네스의 체
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000
using namespace std;

vector<bool> prime(MAX + 1, 1);

void eratos() {
	prime[1] = 0;
	for (int i = 2; i <= MAX; i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= MAX; j += i) prime[j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	eratos();

	int n;
	while (cin >> n) {
		if (n == 0) break;
		bool find = 0;
		int a, b;
		for (a = 3; a <= n; a++) {
			if (a % 2 == 1 && prime[a]) {
				b = n - a;
				if (b % 2 == 1 && prime[b]) {
					find = 1; break;
				}
			}
		}
		if (find) cout << n << " = " << a << " + " << b << '\n';
		else cout << "Goldbach's conjecture is wrong." << '\n';
	}
}
