#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> v;
int n, m;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int x, int y) {
	int cnt = 1;
	v[x][y] = 0;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (v[nx][ny]) cnt += dfs(nx, ny);
	}

	return cnt;
}

int main() {
	int k, r, c; cin >> n >> m >> k;

	v = vector<vector<bool>>(n, vector<bool>(m, 0));

	while (k--) {
		cin >> r >> c;
		v[r - 1][c - 1] = 1;
	}

	int max_area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j]) {
				int area = dfs(i, j);
				if (max_area < area) max_area = area;
			}
		}
	}

	cout << max_area;
}
