#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<vector<int>> nodes;
vector<bool> visited;

void dfs(int cur) {
	visited[cur] = true;
	cout << cur << " ";
	for (int v : nodes[cur]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	visited = vector<bool>(n + 1, false);

	q.push(start); 
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (int v : nodes[cur]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> v;

	nodes.resize(n + 1);
	visited = vector<bool>(n + 1, false);
	
	int n1, n2;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		nodes[n2].push_back(n1);
	}

	for (int i = 1; i <= n; i++) {
		sort(nodes[i].begin(), nodes[i].end());
	}

	dfs(v);
	cout << '\n';
	bfs(v);
}
