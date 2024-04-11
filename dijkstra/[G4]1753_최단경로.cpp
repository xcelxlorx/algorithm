//최단 경로 구하기
//다익스트라
//우선순위 큐 사용 -> 값이 가장 작은 노드 고름
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

vector<vector<pair<int, int>>> vec;
vector<int> dist;
int n, e, s;

void dijkstra() {
	priority_queue<pair<int, int>> pq; //첫번째 기준 내림차순
	dist.resize(n + 1, INF);

	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[node] < cost) continue;

		for (auto p : vec[node]) {
			int next = p.first, weight = p.second;
			if (dist[node] + weight < dist[next]) { //업데이트 될 때 갱신
				dist[next] = dist[node] + weight;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> e >> s;

	vec.resize(n + 1);

	int u, v, w;
	for (int i = 0; i < e; i++) {
		cin >> u >> v >> w;
		vec[u].push_back({ v, w });
	}
	
	dijkstra();

	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}
