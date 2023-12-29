#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m;
vector<vector<bool>> maze;
vector<vector<bool>> visited;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(int i, int j) {
	int min = 987654321;

	queue<tuple<int, int, int>> q; //x, y, l
	q.push({ i, j, 1 });
	visited[i][j] = true;

	while (!q.empty()) {
		tuple<int, int, int> cur = q.front();
		int x = get<0>(cur), y = get<1>(cur), l = get<2>(cur);
		q.pop();

		if (x == n - 1 && y == m - 1) {
			min = min > l ? l : min;
			continue;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (maze[nx][ny] && !visited[nx][ny]) {	
				q.push({ nx, ny, l + 1 });
				visited[nx][ny] = true;
			}
		}
	}
	return min;
}

int main() {
	cin >> n >> m;

	maze = vector<vector<bool>>(n, vector<bool>(m, false));
	visited = vector<vector<bool>>(n, vector<bool>(m, false));
	
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			maze[i][j] = s[j] == '0' ? 0 : 1;
		}
	}

	cout << bfs(0, 0);
}
