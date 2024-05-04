#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, op; cin >> n; 
	vector<int> nums(n), ops;
	for (int i = 0; i < n; i++) cin >> nums[i]; 
	for (int i = 1; i <= 4; i++) {
		cin >> op;
		while (op--) ops.push_back(i);
	}

	long long h = -1000000000, l = 1000000000;
	do {
		long long answer = nums[0];
		for (int i = 0; i < n - 1; i++) {
			if (ops[i] == 1) answer += nums[i + 1];
			else if (ops[i] == 2) answer -= nums[i + 1];
			else if (ops[i] == 3) answer *= nums[i + 1];
			else {
				if (answer < 0) answer = -abs(answer) / nums[i + 1];
				else answer /= nums[i + 1];
			}
		}
		h = max(h, answer); l = min(l, answer);
	} while (next_permutation(ops.begin(), ops.end()));
	cout << h << '\n' << l;
}
