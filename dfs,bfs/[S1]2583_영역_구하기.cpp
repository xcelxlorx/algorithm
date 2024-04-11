#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, h;
vector<vector<int>> map;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int i, int j) {
	int cnt = 1;
	map[i][j] = 1;

	for (int k = 0; k < 4; k++) {
		int nx = dx[k] + i, ny = dy[k] + j;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (!map[nx][ny]) cnt += dfs(nx, ny);
	}
	return cnt;
}

int main() {
	cin >> m >> n >> h;

	map = vector<vector<int>>(n, vector<int>(m, 0));
	
	for (int k = 0; k < h; k++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				if(!map[i][j]) map[i][j] = 1;
			}
		}
	}

	vector<int> answer;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) {
				answer.push_back(dfs(i, j));
			}
		}
	}
	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (auto e : answer) cout << e << " ";
}
