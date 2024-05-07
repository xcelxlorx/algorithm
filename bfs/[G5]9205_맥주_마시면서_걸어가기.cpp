#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int sx, sy, ex, ey;

string bfs(vector<vector<int>>& v) {
	queue<vector<int>> q;
	map<pair<int, int>, bool> visited;
	q.push({ sx, sy });
	visited[{sx, sy}] = 1;
	
	while (!q.empty()) {
		auto p = q.front();
		int x = p[0], y = p[1];
		q.pop();
		if (x == ex && y == ey) return "happy";

		for (auto e : v) {
			int nx = e[0], ny = e[1];
			int d = abs(nx - x) + abs(ny - y);
			if (d == 0 || d > 1000) continue;
			if (!visited[{nx, ny}]) {
				q.push({ e[0], e[1] });
				visited[{e[0], e[1]}] = 1;
			}
		}
	}
	return "sad";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, x, y; cin >> n;

		cin >> sx >> sy;
		vector<vector<int>> v(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v[i] = { x, y };
		}
		cin >> ex >> ey;
		v[n] = { ex, ey };

		cout << bfs(v) << '\n';
	}
}
