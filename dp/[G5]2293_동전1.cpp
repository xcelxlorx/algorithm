//dp
//합이 동전 가치의 배수일 때 더하는 것이 아님
//(합 - 동전 가치)를 고려하는 것
#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, k; cin >> n >> k;

	vector<int> coin(n, 0);
	for (int i = 0; i < n; i++) cin >> coin[i];

	//10^6
	vector<int> dp(k + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int cur = coin[i]; //현재 동전 가치
		for (int j = 1; j <= k; j++) {	
			if (j - cur < 0) continue;
			dp[j] += dp[j - cur]; //dp[j]: 합이 j일 때 개수
		}
	}

	cout << dp[k];
}
