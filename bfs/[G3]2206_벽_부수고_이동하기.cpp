//가중치 없는 최단 경로 -> bfs
//bfs: O(NODE + EDGE)
//완탐 + bfs는 시간초과
//3차원 bfs : 벽을 부수고 온 최단거리, 그냥 온 최단거리

#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int map[1001][1001];
int n, m;
int answer = INF;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int dist[1001][1001][2] = { 0, };

void bfs() {
	queue<vector<int>> q;
	q.push({ 0, 0, 0 }); //x, y, state(벽을 부수면 1)
	dist[0][0][0] = 1; dist[0][0][1] = 1;

	while (!q.empty()) {
		auto v = q.front();
		int x = v[0], y = v[1], state = v[2];
		q.pop();

		if (x == n - 1 && y == m - 1) {
			answer = dist[x][y][state];
			break;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if (map[nx][ny] && !state) { 
				//벽이 있고 이전에 부수지 않은 경우
				q.push({ nx, ny, 1 });
				dist[nx][ny][1] = dist[x][y][state] + 1;
			}else if (!map[nx][ny] && !dist[nx][ny][state]) { 
				//벽이 없고 방문하지 않은 경우
				q.push({ nx, ny, state });
				dist[nx][ny][state] = dist[x][y][state] + 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	string s;
	vector<pair<int, int>> wall;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
			if (map[i][j]) wall.push_back({ i, j });
		}
	}

	bfs();

	if (answer == INF) cout << -1;
	else cout << answer;
}
