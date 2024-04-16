//최소 이동 거리 -> bfs
#include <iostream>
#include <queue>

using namespace std;

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
vector<vector<bool>> visited;

int bfs(int x1, int y1, int x2, int y2, int l) {
	queue<vector<int>> q;
	visited = vector<vector<bool>>(l, vector<bool>(l, 0));
	q.push({ x1, y1, 0 });

	while (!q.empty()) {
		auto v = q.front();
		int x = v[0], y = v[1], d = v[2];
		q.pop();

		if (x == x2 && y == y2) return d;

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
			if (!visited[nx][ny]) {
				q.push({ nx, ny, d + 1 });
				visited[nx][ny] = 1;
			}
		}
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		int l; cin >> l;
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << bfs(x1, y1, x2, y2, l) << '\n';
	}
}
