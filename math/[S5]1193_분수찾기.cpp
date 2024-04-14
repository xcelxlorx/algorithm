#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;

	/*int cnt = 0, state, j;
	for (state = 2; state <= 10000000; state++) {
		for (j = 1; j <= state - 1; j++) {
			cnt++;
			if (cnt == n) break;
		}
		if (cnt == n) break;
	}*/

	int state = 1;
	while (n > state) {
		n -= state;
		state++;
	}

	if (state % 2 == 1) cout << state - n + 1 << "/" << n;
	else cout << n << "/" << state - n + 1;
}
