#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int> visited, answer;
int k;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (visited[node] == k) answer.push_back(node);
			
		for (int next : v[node]) {
			if (visited[next] == -1) {
				visited[next] = visited[node] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x; cin >> n >> m >> k >> x;

	v.resize(n + 1);
	visited = vector<int>(n + 1, -1);

	int n1, n2;
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
	}

	bfs(x);

	sort(answer.begin(), answer.end());

	if (answer.size() == 0) cout << -1;
	else for (auto e : answer) cout << e << '\n';
}
