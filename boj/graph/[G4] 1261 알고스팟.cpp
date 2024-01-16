//bfs + 다익스트라

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<string> v;
int m, n;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dijkstra() {
	queue<pair<int, int>> q;
	vector<vector<int>> dist(n, vector<int>(m, INF));
	
	q.push({ 0, 0 });
	dist[0][0] = 0;

	while (!q.empty()) {
		auto p = q.front();
		int x = p.first, y = p.second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			int state = v[nx][ny] == '1' ? 1 : 0;
			if (dist[nx][ny] > state + dist[x][y]) {
				dist[nx][ny] = state + dist[x][y];
				q.push({ nx, ny });
			}		
		}
	}
	return dist[n - 1][m - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	v.resize(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	cout << dijkstra();
}
