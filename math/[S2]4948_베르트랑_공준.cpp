//에라토스테네스의 체
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 246912

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
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (prime[i]) cnt++;
		}
		cout << cnt << '\n';
	}
}
