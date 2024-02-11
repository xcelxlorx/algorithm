//최장 증가 부분 수열 - LIS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> v(n + 1), dp(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> v[i];

	for (int i = 1; i <= n; i++) {
		int prev = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (v[j] < v[i]) {
				prev = max(prev, dp[j]);
			}
		}
		dp[i] = max(0, prev) + v[i];
	}

	cout << *max_element(dp.begin(), dp.end());
}
