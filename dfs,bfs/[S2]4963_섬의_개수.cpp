#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int w, h;
vector<vector<bool>> map;

int dx[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };

void dfs(int x, int y) {
	map[x][y] = 0;

	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k], ny = y + dy[k];

		if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

		if (map[nx][ny]) dfs(nx, ny);
	}
}

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	map[i][j] = 0;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

			if (map[nx][ny]) {
				q.push({ nx, ny });
				map[nx][ny] = 0;
			}
		}
	}
}

int main() {

	while (1) {
		cin >> w >> h;

		if (w == 0) break;

		map = vector<vector<bool>>(h, vector<bool>(w, 0));
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int a; cin >> a;
				map[i][j] = a;
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}
