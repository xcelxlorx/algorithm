#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n;
vector<vector<int>> v;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dijkstra() {
	queue<pair<int, int>> q;
	vector<vector<int>> dist(n, vector<int>(n, INF));

	q.push({ 0, 0 });
	dist[0][0] = v[0][0];

	while (!q.empty()) {
		auto p = q.front();
		int x = p.first, y = p.second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = dx[k] + x, ny = dy[k] + y;

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			if (dist[nx][ny] > dist[x][y] + v[nx][ny]) {
				dist[nx][ny] = dist[x][y] + v[nx][ny];
				q.push({ nx, ny });
			}
		}
	}

	return dist[n - 1][n - 1];
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	int cnt = 1;
	while (cin >> n) {
		if (!n) break;

		v = vector<vector<int>>(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}

		cout << "Problem " << cnt++ << ": " << dijkstra() << '\n';
	}
}
