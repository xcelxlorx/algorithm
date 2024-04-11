#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v, v_cpy;
vector<vector<bool>> visited;
int n, m;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void check(int x, int y) {
	v[x][y] = -1;
	visited[x][y] = 1;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (!visited[nx][ny] && v[nx][ny] != 1) check(nx, ny);
	}
}

int main() {
	cin >> n >> m;

	v = vector<vector<int>>(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int time = 0;
	while (1) {
		visited = vector<vector<bool>>(n, vector<bool>(m, 0));
		check(0, 0);

		bool flag = 0;
		v_cpy = v;	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

					if (v[nx][ny] == -1) cnt++;
				}
				if (cnt >= 2) v_cpy[i][j] = -1; //치즈 녹이기
				if (v_cpy[i][j] == 1) flag = 1; //치즈 녹았는지 확인
			}
		}
		v = v_cpy;

		time++;

		if (!flag) break;
	}
	cout << time;
}
