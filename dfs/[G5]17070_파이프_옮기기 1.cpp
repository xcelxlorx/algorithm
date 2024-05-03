#include <iostream>
#include <vector>

using namespace std;

int n;
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };
vector<vector<int>> d;
vector<vector<int>> home;
int cnt = 0;

int dfs(int sx, int sy, int state) {
	int cnt = 0;
	int ex = sx + dx[state], ey = sy + dy[state]; //꼬리

	if (ex == n - 1 && ey == n - 1) return 1;

	for (int next : d[state]) {
		if (next == 0) { //가로
			if (ey + 1 >= n) continue;
			if (home[ex][ey + 1] == 0) cnt += dfs(ex, ey, next);
		}
		if (next == 1) { //세로
			if (ex + 1 >= n) continue;
			if (home[ex + 1][ey] == 0) cnt += dfs(ex, ey, next);
		}
		if (next == 2) { //대각선
			int x1 = ex + 1, y1 = ey, x2 = ex, y2 = ey + 1, x3 = ex + 1, y3 = ey + 1;
			if (x1 >= n || y1 >= n || x2 >= n || y2 >= n || x3 >= n || y3 >= n) continue;
			if (home[x1][y1] == 0 && home[x2][y2] == 0 && home[x3][y3] == 0) cnt += dfs(ex, ey, next);
		}
	}

	return cnt;
}

int main() {
	cin >> n;

	home = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> home[i][j];
		}
	}

	d = vector<vector<int>>(3);
	d[0] = { 0, 2 }; d[1] = { 1, 2 }; d[2] = { 0, 1, 2 };

	cout << dfs(0, 0, 0);
}
