#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visited;

int n, m;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	int cnt = 1;
	visited[x][y] = 1;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (!visited[nx][ny] && v[nx][ny]) {
			cnt += dfs(nx, ny);
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	v = vector<vector<int>>(n, vector<int>(m, 0));
	visited = vector<vector<bool>>(n, vector<bool>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int cnt = 0, max_area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && v[i][j]) {
				int area = dfs(i, j);
				max_area = max_area < area ? area : max_area;
				cnt++;
			}
		}
	}

	cout << cnt << '\n' << max_area;
}
