//같을 때는 [i-1][j-1] + 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str1, str2; cin >> str1 >> str2;

	vector<vector<int>> dp(str2.size() + 1, vector<int>(str1.size() + 1, 0));

	for (int i = 1; i <= str2.size(); i++) {
		for (int j = 1; j <= str1.size(); j++) {
			int state = str2[i - 1] == str1[j - 1] ? 1 : 0;
			if(state) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[str2.size()][str1.size()] << '\n';
	if (dp[str2.size()][str1.size()] != 0) {
		string s = "";
		int i = str2.size() - 1, j = str1.size() - 1;
		while (1) {
			if (str2[i] == str1[j]) {
				s = str2[i] + s;
				i--; j--;
			}else {
				if (dp[i + 1][j] > dp[i][j + 1]) j--;
				else i--;
			}
			if (i < 0 || j < 0) break;
		}
		cout << s;
	}
}
