#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
vector<vector<int>> office;
vector<vector<vector<int>>> d; //cctv 숫자에 따라 가능한 방향
vector<vector<int>> cctv;
int answer = 987654321;

void check(vector<vector<int>>& visited, int d, int x, int y) {
	while (1) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
		if (office[nx][ny] == 6) break;
		if (office[nx][ny] == 0) {
			office[nx][ny] = -1;
			visited.push_back({ nx, ny });
		}
		x = nx; y = ny;
	}
}

void back(int idx) {
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (office[i][j] == 0) cnt++;
			}
		}
		answer = min(answer, cnt);
		return;
	}

	int x = cctv[idx][0], y = cctv[idx][1];
	auto v = d[office[x][y]];

	for (int k = 0; k < v.size(); k++) {
		vector<vector<int>> visited;
		for (int cur : v[k]) check(visited, cur, x, y); //칠함
		back(idx + 1);
		for (auto point : visited) office[point[0]][point[1]] = 0; //되돌림
	}
}

int main() {
	cin >> n >> m;

	office = vector<vector<int>>(n, vector<int>(m));
	cctv = vector<vector<int>>();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> office[i][j];
			if (office[i][j] >= 1 && office[i][j] <= 5) {
				cctv.push_back({i, j});
			}
		}
	}

	d = vector<vector<vector<int>>>(6);
	d[1] = { {0}, {1}, {2}, {3} };
	d[2] = { {0, 1}, {2, 3} };
	d[3] = { {0, 2}, {0, 3}, {1, 3}, {1, 2} };
	d[4] = { {0, 1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2, 3} };
	d[5] = { {0, 1, 2, 3} };

	back(0);

	cout << answer;
}
