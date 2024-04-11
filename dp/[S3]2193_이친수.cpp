#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<pair<long long, long long>> dp(n + 1);
	dp[1] = { 1, 0 };

	for (int i = 2; i <= n; i++) {
		dp[i] = { dp[i - 1].second, dp[i - 1].first + dp[i - 1].second };
	}

	cout << dp[n].first + dp[n].second;
}
