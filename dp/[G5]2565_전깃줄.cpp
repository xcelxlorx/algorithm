//dp - 전봇대의 오른쪽 LIS..
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, a, b; cin >> n;

	vector<vector<int>> wire(n + 1, vector<int>(2));
	for (int i = 1; i <= n; i++) cin >> wire[i][0] >> wire[i][1];

	sort(wire.begin(), wire.end());

	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if(wire[i][1] > wire[j][1])	
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}

	cout << n - *max_element(dp.begin(), dp.end());
}
