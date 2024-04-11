#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> dp(10, 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < 10; j++) {
			dp[j] = (dp[j] + dp[j - 1]) % 10007;
		}
	}
	
	cout << accumulate(dp.begin(), dp.end(), 0) % 10007;
}
