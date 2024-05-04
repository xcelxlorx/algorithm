#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }; //북동남서
int dy[4] = { 0, 1, 0, -1 }; 
int n, m, r, c, d;
vector<vector<int>> room;

int cleaning() {
	int cnt = 0;
	int x = r, y = c, state = d;

	while (1) {
		if (room[x][y] == 0) {
			room[x][y] = -1; //청소 완료
			cnt++;
		}

		int blank = 0;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (room[nx][ny] == 0) blank++;
		}

		if (!blank) {
			//빈 칸이 없음
			int nx = x - dx[state], ny = y - dy[state];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (room[nx][ny] == 1) break;
			x = nx; y = ny;
		}
		else {
			//빈 칸이 있음
			state = state - 1 < 0 ? 3 : state - 1; //반시계
			int nx = x + dx[state], ny = y + dy[state];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (room[nx][ny] == 0) {
				x = nx; y = ny;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m >> r >> c >> d;
	room = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}
	cout << cleaning();
}
