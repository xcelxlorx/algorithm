//다익스트라
//최단 거리 배열이 우선순위 큐 배열

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> v;
vector<priority_queue<int>> dist;
int n, m, k;

void dijkstra() {
	dist.resize(n + 1);
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, 1 });
	dist[1].push(0);

	while (!pq.empty()) {
		int node = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();

		for (auto p : v[node]) {
			int next = p.first;
			int next_weight = p.second + weight;

			if (dist[next].size() < k) {
				dist[next].push(next_weight);
				pq.push({ -next_weight, next });
			}else {
				if (next_weight < dist[next].top()) {
					dist[next].pop();
					dist[next].push(next_weight);
					pq.push({ -next_weight, next });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	v.resize(n + 1);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	dijkstra();

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) cout << -1 << '\n';
		else cout << dist[i].top() << '\n';
	}
}
