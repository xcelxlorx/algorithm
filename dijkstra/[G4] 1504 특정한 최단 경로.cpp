//다익스트라
//1-A-B-N or 1-B-A-N

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

vector<vector<pair<int, int>>> v;
int n;

int dijkstra(int start, int end) {
	priority_queue<pair<int, int>> pq;
	vector<int> dist(n + 1, INF);
	
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		auto top = pq.top();
		int node = top.second;
		int weight = -top.first;
		pq.pop();

		for (auto p : v[node]) {
			int next = p.first;
			int next_weight = p.second + weight;
			if (next_weight < dist[next]) {
				dist[next] = next_weight;
				pq.push({ -dist[next], next });
			}
		}
	}

	return dist[end];
}

int check(int v1, int v2) {
	int result = 0;

	int r1 = dijkstra(1, v1);
	if (r1 == INF) return INF;

	int r2 = dijkstra(v1, v2);
	if (r2 == INF) return INF;

	int r3 = dijkstra(v2, n);
	if (r3 == INF) return INF;

	return r1 + r2 + r3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	int e; cin >> n >> e;

	v.resize(n + 1);

	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	int v1, v2; cin >> v1 >> v2;

	int result = min(check(v1, v2), check(v2, v1));

	if (result == INF) cout << -1;
	else cout << result;
}
