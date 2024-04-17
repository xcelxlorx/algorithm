//s -> g까지 가장 빠르게 가는 방법 : bfs
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int f, s, g, u, d;
vector<bool> visited;

int bfs() {
	queue<vector<int>> q;
	visited = vector<bool>(f + 1, 0);
	int dx[2] = { u, -d };

	q.push({ s, 0 });
	visited[s] = 1;

	while (!q.empty()) {
		auto v = q.front();
		int node = v[0], cnt = v[1];
		q.pop();

		if (node == g) return cnt;

		for (int k = 0; k < 2; k++) {
			int next = node + dx[k];
			if (next < 1 || next > f) continue;
			if (!visited[next]) {
				q.push({ next, cnt + 1 });
				visited[next] = 1;
			}
		}
	}

	return -1;
}

int main() {
	cin >> f >> s >> g >> u >> d;
	int answer = bfs();
	if (answer == -1) cout << "use the stairs";
	else cout << answer;
}
