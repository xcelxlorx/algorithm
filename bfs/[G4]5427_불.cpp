#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

vector<vector<char>> map;
vector<vector<int>> f;
int w, h;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void fire() {
	queue<vector<int>> q;
	f = vector<vector<int>>(w, vector<int>(h, INF));

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (map[i][j] == '*') {
				q.push({ i, j }); //x y
				f[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		auto v = q.front();
		int x = v[0], y = v[1];
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
			if (f[nx][ny] == INF && map[nx][ny] != '#') {
				f[nx][ny] = f[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int bfs(int x, int y) {
	queue<vector<int>> q;
	q.push({ x, y, 0 }); // x y cnt
	map[x][y] = '0';

	while (!q.empty()) {
		auto v = q.front();
		int x = v[0], y = v[1], cnt = v[2];
		q.pop();

		if (x == 0 || x == w - 1 || y == 0 || y == h - 1) return cnt + 1;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
			if (map[nx][ny] == '.' && f[nx][ny] > cnt + 1) {
				q.push({ nx, ny, cnt + 1 });
				map[nx][ny] = '0';
			}
		}
	}

	return -1;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> h >> w;
		map = vector<vector<char>>(w, vector<char>(h, 0));
		string s; int x = 0, y = 0;
		for (int i = 0; i < w; i++) {
			cin >> s;
			for (int j = 0; j < h; j++) {
				map[i][j] = s[j];
				if (map[i][j] == '@') {
					x = i, y = j;
				}
			}
		}
		fire();
		int answer = bfs(x, y);
		if (answer == -1) cout << "IMPOSSIBLE\n";
		else cout << answer << '\n';
	}
}
