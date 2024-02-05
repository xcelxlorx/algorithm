#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int dp[101][101][101] = { 0, }; //n, l, r

int main() {
	int n, l, r; cin >> n >> l >> r;

	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				if (j == 1 && k == 1) continue;
				int slot = i - 2; //i - 1개의 건물 사이 개수
				dp[i][j][k] = ((long long)dp[i - 1][j - 1][k] 
					+ (long long)dp[i - 1][j][k - 1] 
					+ (long long)dp[i - 1][j][k] * slot) % MOD;
			}
		}
	}

	cout << dp[n][l][r];
}
