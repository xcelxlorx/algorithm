#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;

int bfs(int start) {
	int cnt = 0;
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int next : v[node]) {
			if (!visited[next]) {
				visited[next] = 1;
				cnt++;
				q.push(next);
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;

	v.resize(n + 1);

	int n1, n2;
	while (m--) {
		cin >> n1 >> n2;
		v[n2].push_back(n1);
	}

	int max_cnt = 0;
	vector<int> answer;
	for (int i = 1; i <= n; i++) {
		visited = vector<bool>(n + 1, 0);

		int cnt = bfs(i);

		if (max_cnt < cnt) {
			max_cnt = cnt;
			answer = { i };
		}
		else if (max_cnt == cnt) answer.push_back(i);
	}

	sort(answer.begin(), answer.end());
	for (int e : answer) cout << e << " ";
}
