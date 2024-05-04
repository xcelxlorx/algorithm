//방문 순서 체크 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> visited;

int cnt = 1;

void dfs(int node) {
	visited[node] = cnt++;

	for (int cur : v[node]) {
		if (!visited[cur]) dfs(cur);
	}
}

int main() {
	int n, m, r; cin >> n >> m >> r;

	v.resize(n + 1);
	visited = vector<int>(n + 1, 0);

	int n1, n2;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());

	dfs(r);

	for (int i = 1; i <= n; i++) cout << visited[i] << '\n';
}
