//L <= 인구 차이 <= R : 오픈 -> 연합
//연합일 경우 (연합의 총 인구수) / (칸의 개수)가 각 칸의 인구수
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> area;
vector<vector<bool>> visited;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, l, r;

int bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> cur;
	q.push({ sx, sy });
	visited[sx][sy] = 1;
	int area_cnt = 0, pop_cnt = 0;  //영역 수, 인구 수

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		area_cnt++;
		pop_cnt += area[x][y];
		cur.push_back({ x, y });

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			
			int diff = abs(area[x][y] - area[nx][ny]);
			if (!visited[nx][ny] && diff >= l && diff <= r) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}
		}
	}

	//연합 인구수 조정
	int move = pop_cnt / (double)area_cnt;
	for (auto p : cur) area[p.first][p.second] = move;
	return cur.size();
}

int main() {
	cin >> n >> l >> r;

	area = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> area[i][j];
		}
	}
	
	int cnt = 0;
	while (1) {
		int fin = 1;
		visited = vector<vector<bool>>(n, vector<bool>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					int uni = bfs(i, j);
					if (uni != 1) fin = 0;
				}
			}
		}
		if (fin) break;
		cnt++;
	}
	cout << cnt;
}
