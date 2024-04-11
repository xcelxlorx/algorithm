//다익스트라
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

vector<vector<pair<int, int>>> v;
int n;

int dijkstra(int start, int end) {
	priority_queue<pair<int, int>> pq;
	vector<int> cost(n + 1, INF);
	vector<bool> visited(n + 1, 0);

	pq.push({ 0, start });
	cost[start] = 0;

	while (!pq.empty()) {
		int weight = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		if (cost[cur] < weight) continue;

		if (!visited[cur]) {
			visited[cur] = 1;

			for (auto p : v[cur]) {
				int next = p.first, next_weight = p.second;
				if (cost[next] > cost[cur] + next_weight) {
					cost[next] = cost[cur] + next_weight;
					pq.push({ -cost[next], next });
				}
			}
		}
	}
	return cost[end];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m; cin >> n >> m;

	v.resize(n + 1);

	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		v[a].push_back({ b, w });
	}

	int start, end; cin >> start >> end;

	cout << dijkstra(start, end);
}
