#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) cin >> dp[i];

	int result = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + dp[i], dp[i]);
		result = max(result, dp[i]);
	}

	cout << result;
}
