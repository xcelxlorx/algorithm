#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, t, p; cin >> n;
	vector<int> dp(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		cin >> t >> p;
		dp[i] = max(dp[i], dp[i - 1]);
		if (i + t > n + 1) continue;
		dp[i + t - 1] = max(dp[i - 1] + p, dp[i + t - 1]);
	}

	cout << dp[n];
}
