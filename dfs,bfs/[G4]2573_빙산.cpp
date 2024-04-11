#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v, v_cpy;
int n, m;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
	v_cpy[x][y] = 0;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;	
		if (v_cpy[nx][ny]) dfs(nx, ny);
	}
}

void melt() {
	v_cpy = vector<vector<int>>(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (!v[nx][ny]) cnt++;
			}

			v_cpy[i][j] = max(v[i][j] - cnt, 0);
		}
	}

	v = v_cpy;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	v = vector<vector<int>>(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int year = 0, area = 0;
	while (1) {
		melt();

		area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v_cpy[i][j]) {
					dfs(i, j);
					area++;
				}
			}
		}
		year++;

		if (area != 1) break;
	}

	if (area) cout << year;
	else cout << 0;
}
