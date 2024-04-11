#include <iostream>
#include <vector>
#define MOD 1000000000
using namespace std;

int main() {
	int n; cin >> n;

	vector<long long> dp(10, 1); 
	dp[0] = 0;

	for (int i = 2; i <= n; i++) {
		vector<long long> temp = dp;
		temp[0] = dp[1] % MOD;
		for (int j = 1; j <= 8; j++) {
			temp[j] = (dp[j - 1] + dp[j + 1]) % MOD;
		}
		temp[9] = dp[8] % MOD;
		dp = temp;
	}
	
	long long sum = 0;
	for (long long e : dp) sum += e;
	cout << sum % MOD;
}
