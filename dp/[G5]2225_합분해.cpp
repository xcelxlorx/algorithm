//dp
//k를 2에서부터 증가시킴
//기본 dp는 초기화 1(k가 1일 경우)
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k; cin >> n >> k;

	vector<int> dp(n + 1, 1);
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[j] = (dp[j] + dp[j - 1]) % 1000000000;
		}
	}
	cout << dp[n];
}
