//DP는 long long..
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	vector<vector<long long>> dp(n, vector<long long>(n, 0));
	dp[0][0] = 1;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (x == n - 1 && y == n - 1) continue;
			int dx[2] = { 0, v[x][y] }, dy[2] = { v[x][y], 0 };		
			for (int k = 0; k < 2; k++) {
				int nx = dx[k] + x, ny = dy[k] + y;
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				dp[nx][ny] = dp[x][y] + dp[nx][ny];
			}
		}
	}
	cout << dp[n - 1][n - 1];
}
