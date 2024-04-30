//무방향 그래프, 모든 정점 최소 비용 연결 -> mst
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<pair<int, int>>> edge;

int prim() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	vector<bool> visited(n + 1, 0);
	int cost = 0;

	while (!pq.empty()) {
		int cur_cost = pq.top().first, node = pq.top().second;
		pq.pop();

		if (visited[node]) continue;
		visited[node] = 1;

		cost += cur_cost;
		
		for (auto next : edge[node]) pq.push(next);
	}

	return cost;
}

int main() {
	int m, a, b, c; cin >> n >> m;

	edge = vector<vector<pair<int, int>>>(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ c, b });
		edge[b].push_back({ c, a });
	}

	cout << prim();
}
