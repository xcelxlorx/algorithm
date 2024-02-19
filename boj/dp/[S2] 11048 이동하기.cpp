#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
		}
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] }) + v[i][j];
		}
	}
	cout << dp[n][m];
}
