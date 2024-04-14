#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	int next = 0, cur = n, cnt = 0;
	while (true) {
		int sum = cur / 10 + cur % 10;
		int right = cur % 10;
		next = right * 10 + sum % 10;
		cnt++;
		cur = next;
		if (n == next) break;
	}
	cout << cnt;
}
