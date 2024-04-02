#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, m, a, b; cin >> n >> m;

	vector<vector<int>> graph(n + 1);
	vector<int> edge(n + 1);
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		edge[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!edge[i]) q.push(i);
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";

		for (int next : graph[node]) {
			edge[next]--;
			if (!edge[next]) q.push(next);
		}
	}
}
