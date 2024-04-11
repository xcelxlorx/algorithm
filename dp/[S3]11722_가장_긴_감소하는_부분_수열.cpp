#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> v(n), dp(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];

	dp[0] = 1;
	int answer = 1; 
	for (int i = 1; i < n; i++) {
		int temp = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (v[i] < v[j]) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp == -1 ? 1 : temp + 1;
		answer = max(answer, dp[i]);
	}
	cout << answer;
}
