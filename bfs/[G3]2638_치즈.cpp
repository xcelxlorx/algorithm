#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<vector<int>> paper;

int bfs() {
	queue<vector<int>> q;
	vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> check(n + 1, vector<int>(m + 1, 0));
	q.push({0, 0}); //x y
	visited[0][0] = 1;

	while (!q.empty()) {
		auto v = q.front();
		int x = v[0], y = v[1];
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx > n || ny < 0 || ny > m) continue;

			if (!paper[x][y] && paper[nx][ny]) check[nx][ny]++;

			if (!visited[nx][ny] && !paper[nx][ny]) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}
		}
	}

	int cheese = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check[i][j] >= 2) {
				paper[i][j] = 0;
				cheese = 1;
			}
		}
	}
	return cheese;
}

int main() {
	cin >> n >> m;

	paper = vector<vector<int>>(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> paper[i][j];
		}
	}

	int answer = 0;
	while (1) {
		int cur = answer + bfs();
		if (answer == cur) break;
		answer = cur;
	}
	cout << answer;
}
