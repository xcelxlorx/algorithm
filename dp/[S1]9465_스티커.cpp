//타일 모양 그려보기
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		vector<vector<int>> v(2, vector<int>(n));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}

		vector<vector<int>> dp = v;
		dp[0][1] = dp[1][0] + v[0][1]; 
		dp[1][1] = dp[0][0] + v[1][1];

		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + v[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + v[1][i];
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}
}
