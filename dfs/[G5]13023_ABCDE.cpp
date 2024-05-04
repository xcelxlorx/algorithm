#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> v;
bool answer = 0;

void dfs(int cur, int depth) {
	if (depth == 5) {
		answer = 1;
		return;
	}
	visited[cur] = true;
	for (int next : v[cur]) {
		if (!visited[next]) {
			dfs(next, depth + 1);
		}
	}
	visited[cur] = false;
}

int main() {
	int n, m; cin >> n >> m;

	v.resize(n);
	visited = vector<bool>(n, false);
	
	int n1, n2;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}

	for (int i = 0; i < n; i++) {
		if (answer) break;
		dfs(i, 1);
	}
	cout << answer << '\n';
}
