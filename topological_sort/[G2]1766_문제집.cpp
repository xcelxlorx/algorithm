#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b; cin >> n >> m;

	vector<int> edge(n + 1, 0);
	vector<vector<int>> graph(n + 1);
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		edge[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (!edge[i]) pq.push(i);
	}

	while (!pq.empty()) {
		int top = pq.top();
		pq.pop();
		cout << top << " ";

		for (int next : graph[top]) {
			edge[next]--;
			if (!edge[next]) pq.push(next);
		}
	}
}
