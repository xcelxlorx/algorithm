//DFS + DP
//그냥 DFS로 풀면 시간초과
//dp가 0일 때 경로가 없는 것인지 처음 방문한 것인지 구별이 안됨
//dp 배열은 0이 아닌 -1로 초기화

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> dp;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int m, n;

int dfs(int x, int y) {
	if (x == m - 1 && y == n - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y]; //이미 탐색한 경우 오르막이므로 그대로 반환

	dp[x][y] = 0;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];

		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

		if (map[nx][ny] < map[x][y]) dp[x][y] += dfs(nx, ny);
	}

	return dp[x][y]; //탐색 결과 반환
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	map = vector<vector<int>>(m, vector<int>(n, 0));
	dp = vector<vector<int>>(m, vector<int>(n, -1));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(0, 0);
}
