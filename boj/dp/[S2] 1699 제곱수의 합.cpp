#include <iostream>
#include <vector>
#include <cmath>
#define INF 987654321
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> dp(n + 1, INF);
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int cur = 1; cur * cur <= i; cur++) {
			dp[i] = min(dp[i], dp[i - cur * cur] + 1);
		}
	}
	cout << dp[n];
}
