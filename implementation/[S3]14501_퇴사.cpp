#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, t, p; cin >> n;
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> t >> p;
		int d = i + t - 1;
		if (d <= n) dp[d] = max(dp[d], dp[i - 1] + p);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n];
}
