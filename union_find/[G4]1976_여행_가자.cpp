//유니온 파인드
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph;

int find_node(int node) {
	if (graph[node] == node) return node;
	graph[node] = find_node(graph[node]);
	return graph[node];
}

void merge(int a, int b) {
	int ranode = find_node(a);
	int rbnode = find_node(b);

	if (ranode != rbnode) graph[ranode] = rbnode;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	graph.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) graph[i] = i;

	bool state;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> state;
			if (state == 1) merge(i, j);
		}
	}

	int plan, prev = -1;
	bool flag = 1;
	for (int i = 0; i < m; i++) {
		cin >> plan;
		int cur = find_node(plan);
		if (prev == -1) {
			prev = cur;
			continue;
		}
		if (prev != cur) {
			flag = 0;
			break;
		}
	}

	if (flag) cout << "YES";
	else cout << "NO";
}
