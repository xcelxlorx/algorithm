//블록은 짝수 너비일 경우만
//홀수는 다 0
//짝수는 합칠 수 있음
//[i][0]: 앞의 블록이랑 분리될 경우, [i][1]: 앞의 블록이랑 합쳐질 경우
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<vector<int>> dp(n + 1, vector<int>(2, 0));
	dp[0][0] = 1;
	for (int i = 2; i <= n; i += 2) {
		dp[i][0] = (dp[i - 2][0] + dp[i - 2][1]) * 3;
		if (i == 2) continue;
		dp[i][1] = (dp[i - 4][0] + dp[i - 4][1]) * 2 + dp[i - 2][1];
	}
	cout << dp[n][0] + dp[n][1];
}
