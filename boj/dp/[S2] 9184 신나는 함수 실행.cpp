#include <iostream>
#include <cstring>

using namespace std;

int dp[21][21][21] = { 0, };

int re(int i, int j, int k) {
	if (i <= 0 || j <= 0 || k <= 0) return 1;
	if (i > 20 || j > 20 || k > 20) return re(20, 20, 20);
	if (dp[i][j][k] != 0) return dp[i][j][k];
	if (i < j && j < k) dp[i][j][k] = re(i, j, k - 1) + re(i, j - 1, k - 1) - re(i, j - 1, k);
	else dp[i][j][k] = re(i - 1, j, k) + re(i - 1, j - 1, k) + re(i - 1, j, k - 1) - re(i - 1, j - 1, k - 1);
	return dp[i][j][k];
}

int main() {
	int a, b, c;
	while (cin >> a >> b >> c && !(a == -1 && b == -1 && c == -1)) {
		cout << "w(" << a << ", " << b << ", " << c << ") = " << re(a, b, c) << '\n';
	}
}
