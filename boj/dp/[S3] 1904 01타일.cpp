//1, 00 타일
//피보나치 수열

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> dp(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[n];
}
