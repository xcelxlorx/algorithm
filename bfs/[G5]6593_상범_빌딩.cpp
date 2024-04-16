//최단시간 -> bfs
#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

string b[31][31][31];
int l, r, c;
int dx[6] = { 1, -1, 0, 0, 0, 0 }; //동서남북상하
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int answer = INF;

void bfs(int x, int y, int z) {
	queue<vector<int>> q;
	q.push({ x, y, z, 0 }); // x y z time

	while (!q.empty()) {
		auto v = q.front();
		x = v[0], y = v[1], z = v[2];
		q.pop();

		if (b[z][x][y] == "E") {
			answer = min(answer, v[3]);
			continue;
		}

		for (int k = 0; k < 6; k++) {
			int nx = x + dx[k], ny = y + dy[k], nz = z + dz[k];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
			if (b[nz][nx][ny] != "#") {
				if(b[nz][nx][ny] != "E") b[nz][nx][ny] = "#";
				q.push({ nx, ny, nz, v[3] + 1 });
			}
		}
	}
}

int main() {
	while (cin >> l >> r >> c) {
		if (l == 0 && r == 0 && c == 0) break;

		string str;
		int x = 0, y = 0, z = 0;
		answer = INF;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> str;
				for (int k = 0; k < c; k++) {
					if (str.size() > 0) b[i][j][k] = str[k];
					if (str[k] == 'S') {
						x = j; y = k; z = i;
					}
				}
			}
		}

		bfs(x, y, z);

		if (answer != INF) cout << "Escaped in " << answer << " minute(s).\n";
		else cout << "Trapped!\n";
	}
}
