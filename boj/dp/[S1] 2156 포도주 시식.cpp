#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> v[i];

	vector<int> dp(n + 1, 0);
	dp[1] = v[1]; dp[2] = v[1] + v[2];
	for (int i = 3; i <= n; i++) {
		//i-3 ~ i의 전체 경우의 수 고려
		//i-3(O), i-2(X), i-1(O), i(O) -> dp[i - 2] + v[i]
		//i-3(O), i-2(O), i-1(X), i(O) -> dp[i - 3] + v[i - 1] + v[i]
		//i-3(O), i-2(X), i-1(X), i(O) -> dp[i - 3] + v[i](위의 값이 항상 큼)
		//i-3(?), i-2(?), i-1(?), i(X) -> dp[i - 1]
		dp[i] = max({ dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i], dp[i - 1] });
	}

	cout << *max_element(dp.begin(), dp.end());
}
