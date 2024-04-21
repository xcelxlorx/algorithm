#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, x, y, k, d; cin >> n >> m >> x >> y >> k;

	vector<vector<int>> v(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int dice[4][3] = { 0, };
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };
	for (int i = 0; i < k; i++) {
		cin >> d;
		int nx = x + dx[d - 1], ny = y + dy[d - 1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		x = nx; y = ny;

		//주사위 이동
		if (d == 1) {
			int temp = dice[1][0];
			dice[1][0] = dice[1][1];
			dice[1][1] = dice[1][2];
			dice[1][2] = dice[3][1];
			dice[3][1] = temp;
		}
		else if (d == 2) {
			int temp = dice[1][2];
			dice[1][2] = dice[1][1];
			dice[1][1] = dice[1][0];
			dice[1][0] = dice[3][1];
			dice[3][1] = temp;
		}
		else if (d == 3) {
			int temp = dice[3][1];
			for (int j = 3; j > 0; j--) {
				dice[j][1] = dice[j - 1][1];
			}
			dice[0][1] = temp;
		}
		else {
			int temp = dice[0][1];
			for (int j = 0; j < 3; j++) {
				dice[j][1] = dice[j + 1][1];
			}
			dice[3][1] = temp;
		}

		//주사위 바닥면 
		if (v[nx][ny] == 0) {	
			v[nx][ny] = dice[1][1];
		}
		else {
			dice[1][1] = v[nx][ny];
			v[nx][ny] = 0;
		}

		//주사위 윗 면 출력
		cout << dice[3][1] << '\n'; 
	}
}
