#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> dp(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n];
}
