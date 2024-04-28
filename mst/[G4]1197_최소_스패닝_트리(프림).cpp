#include <iostream>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;

vector<vector<P>> edge;
int v, e;

long long prim() {
	//가중치가 가장 낮은 노드를 top으로 -> pq
	priority_queue<P, vector<P>, greater<P>> pq; //오름차순
	pq.push({0, 1}); //1번 정점부터 시작, 가중치-노드
	vector<bool> visited(v + 1, 0);

	long long sum = 0;
	while (!pq.empty()) {
		int weight = pq.top().first, node = pq.top().second;
		pq.pop();
		
		if (visited[node]) continue;
		visited[node] = 1;

		sum += weight;

		for (auto next : edge[node]) {
			if (!visited[next.second]) {
				pq.push(next); 
				//pq에 넣을 때 visited를 true로 하면, 가중치가 가장 적은 것을 찾기 어려움
			}
		}
	}
	return sum;
}

int main() {
	int a, b, c; cin >> v >> e;

	edge = vector<vector<pair<int, int>>>(v + 1);
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ c, b }); //가중치, 노드
		edge[b].push_back({ c, a });
	}

	cout << prim();
}
