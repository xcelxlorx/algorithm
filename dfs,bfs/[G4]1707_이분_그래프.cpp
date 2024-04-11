//이분 그래프 - 인접한 두 점이 다른 색
//dfs, bfs

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vec;
vector<int> visited;
int v;

void dfs(int node, int state) {
	visited[node] = state;

	for (int next : vec[node]) {
		if (visited[next] == -1) dfs(next, !state);
	}
}

bool check() {
	for (int i = 1; i <= v; i++) {
		for (int next : vec[i]) {
			if (visited[i] == visited[next]) return 0;
		}
	}
	return 1;
}

int main() {
	int k, e, n1, n2; cin >> k;

	while (k--) {
		cin >> v >> e;

		vec = vector<vector<int>>(v + 1);
		visited = vector<int>(v + 1, -1);

		while (e--) {
			cin >> n1 >> n2;
			vec[n1].push_back(n2);
			vec[n2].push_back(n1);
		}

		for (int i = 1; i <= v; i++) {
			if (visited[i] == -1) dfs(i, 1);
		}

		if (check()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
