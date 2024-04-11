#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];

	vector<int> dp = v;
	for (int i = 2; i <= n; i++) {
		int mv = dp[i];
		for (int j = 1; j <= i / 2; j++) {
			mv = max(mv, dp[j] + dp[i - j]);
		}
		dp[i] = mv;
	}
	cout << dp[n];
}
