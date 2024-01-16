//최소 비용 구하기
//우선순위 큐

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<int> pre;

void dijkstra(int start, int end) {
	priority_queue<pair<int, int>> pq; //비용, 노드
	dist.resize(n + 1, INF);
	pre.resize(n + 1);

	pq.push({ 0, { start } });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[end] < cost) continue;

		for (auto p : graph[node]) {
			int next = p.first, next_cost = cost + p.second;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ -dist[next], next });
				pre[next] = node;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m; cin >> n >> m;

	graph.resize(n + 1);

	int n1, n2, cost;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2 >> cost;
		graph[n1].push_back({ n2, cost });
	}

	int start, end; cin >> start >> end;

	dijkstra(start, end);

	vector<int> answer;
	int cur = end;
	while (1) {
		answer.push_back(cur);
		if (cur == start) break;
		cur = pre[cur];
	}

	cout << dist[end] << '\n';
	cout << answer.size() << '\n';
	for (int i = answer.size() - 1; i >= 0; i--) 
		cout << answer[i] << " ";
}
