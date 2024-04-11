//dp[n][l][r]: n개를 수행한 후 왼발이 l 오른발이 r일 때 힘
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[100001][5][5];
vector<int> v;

int dist(int a, int b) {
	if (a == 0 || b == 0) return 2;
	if (a == b) return 1;
	if (abs(a - b) == 2) return 4;
	return 3;
}

int dfs(int idx, int l, int r) {
	if (idx == v.size()) return 0; //마지막 0
	if (dp[idx][l][r] != -1) return dp[idx][l][r];
	int left = dist(l, v[idx]) + dfs(idx + 1, v[idx], r);
	int right = dist(r, v[idx]) + dfs(idx + 1, l, v[idx]);
	return dp[idx][l][r] = min(left, right);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while (cin >> n && n != 0) v.push_back(n);
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, 0);
}
