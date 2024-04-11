//조합 mCn
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;

		//nCm = n-1Cm + n-1Cm-1, nC0 = 1
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				if (i <= 1 || j == 0 || i == j) {
					dp[i][j] = 1;
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
		cout << dp[m][n] << '\n';
	}
}
